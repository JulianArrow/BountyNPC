#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "WorldSession.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Random.h"
#include "DatabaseEnv.h"
#include <iostream>
#include "Chat.h"
#include <cstdlib>
#include <ctime>
 
 
class Bounty_NPC : public CreatureScript
{
public:
    Bounty_NPC() : CreatureScript("Bounty_NPC") { }
 
    struct MyAI : public ScriptedAI
    {
        MyAI(Creature* creature) : ScriptedAI(creature) { }
 
        bool GossipHello(Player* player) override
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Give me a random bounty quest!", GOSSIP_SENDER_MAIN, 0);
            SendGossipMenuFor(player, 907, me->GetGUID());
            return true;
 
        }
 
        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {	
			QueryResult result = WorldDatabase.PQuery("SELECT ID FROM bounty_quests");
            if (!result) {
				TC_LOG_ERROR("server.loading", "Bounty NPC: questIds query got no result");
				return false;
			}

            std::vector<int32> questIds;
            do
            {
                questIds.push_back(result->Fetch()[0].GetInt32());
            } while (result->NextRow());

			std::stringstream ss;
			bool onQuest = false;
			int questCount = questIds.size();
			
			for (int i=0; i < questCount; i++) {
				if (onQuest == false && player->GetQuestStatus(questIds[i]) == QUEST_STATUS_INCOMPLETE) {
						onQuest = true;
				}
			}
			
			
			if (!onQuest) {
				srand((int)time(0));
				int r = (rand() % (questCount));
				Quest const* quest = sObjectMgr->GetQuestTemplate(questIds[r]);
                if (!quest) {
                    TC_LOG_ERROR("server.loading", "Bounty NPC: unable to find quest template");
                    return false;
                }

				if (player->CanAddQuest(quest, true))
					player->AddQuestAndCheckCompletion(quest, NULL);
				
				ss << "|cff00ff00You got your random quest!";
			} else {
				ss << "|cffff0000You already work on one of my quests!";
			}
			
			std::string account = ss.str();
			player->GetSession()->SendAreaTriggerMessage(account.c_str());
			ChatHandler(player->GetSession()).PSendSysMessage(account.c_str());
			CloseGossipMenuFor(player);
            return true;
        }
    };
 
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new MyAI(creature);
    }
 
};
 
void AddSC_Bounty_NPC()
{
    new Bounty_NPC();
}
