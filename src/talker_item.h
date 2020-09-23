#pragma once
#ifndef CATA_SRC_TALKER_ITEM_H
#define CATA_SRC_TALKER_ITEM_H

#include <string>
#include <vector>

#include "talker_character.h"
#include "talker_npc.h"
#include "type_id.h"

class Character;
class character_id;
class faction;
class item;
class mission;
class npc;
class player;
class recipe;
class talker;
class vehicle;
struct tripoint;

class talker_item : public talker_npc
{
    public:
        talker_item( npc *new_me ): talker_npc( new_me ) {
        }
        ~talker_item() override = default;

        // identity and location
        std::string distance_to_goal() const override;

        // mandatory functions for starting a dialogue
        bool will_talk_to_u(const player& u, bool force) override;
        std::vector<std::string> get_topics( bool radio_contact ) override;
        
        // inventory, buying, and selling
        std::string give_item_to( bool to_use ) override;

        // other descriptors
        std::string evaluation_by( const talker &alpha ) const override;
};
#endif // CATA_SRC_TALKER_ITEM_H
