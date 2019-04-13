#pragma once
#include "../../inc.hpp"
#include "../autowall/autowall.h"
#include "../misc/misc.h"
#include "../entity listener/ent_listener.h"
#include "../backtrack/backtrack.h"

class c_ragebot {
	struct rage_t {
		rage_t( c_csplayer *player, lag_record_t *record, int i, int damage, vec3_t point, float dist, matrix3x4_t* matrix ){
			m_player = player;
			m_record = record;
			index = i;
			m_damage = damage;
			m_bestpoint = point;
			distance = dist;
			mat = matrix;
		}

		vec3_t m_bestpoint;
		c_csplayer* m_player;
		lag_record_t* m_record;
		int index;
		int m_damage;
		float distance;
		matrix3x4_t* mat;
	};

	std::vector< rage_t > m_players;
	c_user_cmd *m_cmd;

	void choose_angles( );
	void select_target( );
	void restore_players( );
	bool get_points_from_hitbox( c_csplayer * e, std::vector< int > hitboxes, matrix3x4_t* matrix, std::vector<vec3_t>& points, float scale );
	void quickstop( c_base_combat_weapon *local_weapon );
	bool is_valid( c_csplayer * player );
	bool hitchance( vec3_t &angle, c_csplayer *ent );
	static std::vector< lag_record_t > get_best_records( std::deque< lag_record_t > records );

public:
	int shots_fired;
	c_csplayer *m_last_target = nullptr;

	void work( c_user_cmd * cmd );
	void auto_revolver( c_base_combat_weapon *local_weapon, c_user_cmd *cmd );
};

extern c_ragebot g_ragebot;