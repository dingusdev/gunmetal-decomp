
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void win_init_game(void)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  _DAT_004aa390 = (_DAT_004ac060 + _DAT_004aa390) * 0.5;
  _DAT_004aa398 = (_DAT_004ac068 + _DAT_004aa398) * 0.5;
  _DAT_004aa438 = (_DAT_004aa438 + _DAT_004aa430) * 0.5;
  bVar3 = false;
  level_briefing();
  if (game_hostmode == 4) {
    return;
  }
  if ((char)level_name != '\0') {
    if (game_hostmode == 0) {
      iVar4 = load_world();
      if (iVar4 != 0) {
        menu_visible = 5;
        side_screen = 0;
      }
    }
    else {
      uVar6 = 0xffffffff;
      puVar8 = &level_name;
      do {
        puVar9 = puVar8;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        puVar9 = (undefined4 *)((int)puVar8 + 1);
        cVar1 = *(char *)puVar8;
        puVar8 = puVar9;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      puVar8 = (undefined4 *)((int)puVar9 - uVar6);
      puVar9 = &game_name;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined *)puVar9 = *(undefined *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      level_name._0_1_ = '\0';
    }
  }
  if (((char)game_name != '\0') && (iVar4 = net_retrieve_level(), iVar4 != 0)) {
    menu_visible = 5;
    side_screen = 0;
  }
  if (side_screen == 1) {
    init_game_players_and_objects();
    return;
  }
  if (side_screen == 0) {
    refresh_screen();
    if (setting_on == 0) {
      return;
    }
    init_sound_loop(LevelTicksTotal);
    return;
  }
  client_frame_ticks = LevelTicksTotal - DAT_005a49e8;
  DAT_005a49e8 = LevelTicksTotal;
  if (0x2d < client_frame_ticks) {
    client_frame_ticks = 0x2d;
  }
  puVar8 = &DAT_004ac078;
  iVar4 = 0;
  do {
    iVar5 = find_srcplayer(*(undefined4 *)((int)&player1_ptr + iVar4));
    *(int *)((int)&src_player1 + iVar4) = iVar5;
    if (-1 < iVar5) {
      *puVar8 = *(undefined4 *)(&player_external_dmgflag1 + iVar5 * 0x3510);
      puVar8[1] = *(undefined4 *)(&player_external_dmgflag2 + iVar5 * 0x3510);
    }
    puVar8 = puVar8 + 2;
    iVar4 = iVar4 + 4;
  } while ((int)puVar8 < 0x4ac088);
  if (chat_toggle == 0) {
    bVar2 = true;
    if ((-1 < src_player1) && ((&tank_screen)[src_player1 * 0xd44] == 5)) {
      bVar2 = false;
    }
    if ((-1 < src_player2) && ((&tank_screen)[src_player2 * 0xd44] == 5)) {
      bVar2 = false;
    }
    if (((menu_visible == 0) && (bVar2)) ||
       ((menu_visible == 3 && (iVar4 = deathmatch_game(), iVar4 != 0)))) goto LAB_0044c45f;
  }
  else {
    init_chat();
  }
  bVar3 = true;
LAB_0044c45f:
  if (bVar3) {
    spare_ticks = 0x2d;
  }
  else if (spare_ticks < client_frame_ticks) {
    spare_ticks = 0;
  }
  else {
    spare_ticks = spare_ticks - client_frame_ticks;
  }
  if (spare_ticks == 0) {
    init_tweak_input();
  }
  else {
    game_clear_player_control(0);
    p1_input_setting = 0;
    game_clear_player_control(1);
    DAT_004ac088 = 1;
    p2_input_setting = 0;
    _DAT_004ac08c = 1;
    _DAT_004ac090 = 1;
  }
  game_display_debug_stats(LevelTicksTotal);
  if (((menu_visible == 0) || ((menu_visible == 3 && (iVar4 = deathmatch_game(), iVar4 != 0)))) &&
     (DAT_005a4700 == 2)) {
    _DAT_005a4708 = _DAT_005a4708 - (double)(DAT_005a49fc - DAT_005a49f8) * -18.0;
    _DAT_005a4710 = _DAT_005a4710 - (double)(p1_control_array - DAT_005a49f4) * -18.0;
    _DAT_005a4718 = _DAT_005a4718 - (double)(DAT_005a4a1c - DAT_005a4a20) * -16.0;
  }
  if (_DAT_005a46d0 != 0) {
    local_game_timer_restart();
    return;
  }
  if (game_hostmode != 1) {
    win_game_synch();
    return;
  }
  if (spare_ticks == 0) {
    win_init_nw_packets(client_frame_ticks,&DAT_004ac078,DAT_004ac074,p1_input_setting,DAT_005a4a80,
                        &p1_control_array,p2_input_setting,DAT_005a4a84,&p2_control_array,
                        &DAT_005a4a88,&DAT_005a4a98);
    return;
  }
  win_init_nw_packets(client_frame_ticks,&DAT_004ac078,DAT_004ac074,p1_input_setting,DAT_005a4a80,
                      &p1_control_array,p2_input_setting,DAT_005a4a84,&p2_control_array,
                      &DAT_005a4a88,&DAT_005a4a98);
  return;
}

void __fastcall win_game_synch(int game_ticks)

{
  undefined4 uVar1;
  double dVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int *piVar10;
  
  if (net_game_action == 0) {
    if (hard_locked_fps == 0) {
      game_ticks = LevelTicksTotal - WorldTicks;
      WorldTicks = WorldTicks + game_ticks;
    }
    else {
      game_ticks = (int)(0x5b / (longlong)hard_locked_fps);
      WorldTicks = WorldTicks + game_ticks;
      do {
      } while (LevelTicksTotal < WorldTicks);
    }
    if (0x2d < game_ticks) {
      game_ticks = 0x2d;
    }
    gm_mem_loc = gm_mem_loc + game_ticks;
    if (add_time_stamp != 0) {
      DAT_004a6a28 = gm_mem_loc;
    }
  }
  if ((game_hostmode == 2) || (game_hostmode == 3)) {
    if (LevelTicksTotal < DAT_005a49d8) {
      DAT_005a49d8 = LevelTicksTotal;
    }
    do {
      net_get_client_status();
    } while (LevelTicksTotal <= DAT_005a49d8 + DAT_004aa388);
    DAT_005a49d8 = LevelTicksTotal;
  }
  src_player1 = find_srcplayer(player1_ptr);
  src_player2 = find_srcplayer(player2_ptr);
  if ((net_game_action == 0) && (game_ticks != 0)) {
    if ((game_hostmode == 2) || (game_hostmode == 3)) {
      handle_local_game_ticks(game_ticks,src_player1,src_player2);
    }
    if (side_screen != 2) {
      handle_item_slice(game_ticks);
      update_door_positions(game_ticks);
      update_lift_positions(game_ticks);
    }
    iVar9 = src_player2;
    iVar5 = src_player1;
    if ((spare_ticks == 0) && (DAT_005a4700 != 2)) {
      if (src_player1 < 0) {
        game_clear_player_control(0);
        iVar9 = src_player2;
      }
      else {
        dVar2 = (double)CONCAT44(_DAT_005a4a8c,_DAT_005a4a88);
        _DAT_005a4a88 = 0;
        _DAT_005a4a8c = 0;
        iVar4 = src_player1 * 0x3510;
        (&srcplayer_flags)[src_player1 * 0xd44] =
             (&srcplayer_flags)[src_player1 * 0xd44] ^
             (player_1_options ^ (&srcplayer_flags)[src_player1 * 0xd44]) & 0x11d400;
        (&DAT_0081c380)[iVar5 * 0xd44] = p1_input_setting;
        (&weapon_flags_misc)[iVar5 * 0xd44] = DAT_005a4a80;
        uVar1 = DAT_004ac078;
        *(undefined4 *)(&DAT_0081c404 + iVar4) = DAT_004ac074;
        fVar3 = FLOAT_004ac07c;
        *(undefined4 *)(&player_external_dmgflag1 + iVar4) = uVar1;
        *(float *)(&player_external_dmgflag2 + iVar4) = fVar3;
        DAT_004ac074 = 0xffffffff;
        puVar8 = &player_mvmt_flags + iVar5 * 0xd44;
        (&DAT_0081bf78)[iVar5 * 0x6a2] = dVar2 + (double)(&DAT_0081bf78)[iVar5 * 0x6a2];
        dVar2 = (double)CONCAT44(_DAT_005a4a9c,_DAT_005a4a98);
        _DAT_005a4a98 = 0;
        _DAT_005a4a9c = 0;
        (&DAT_0081bf80)[iVar5 * 0x6a2] = dVar2 + (double)(&DAT_0081bf80)[iVar5 * 0x6a2];
        puVar7 = &p1_control_array;
        do {
          puVar6 = puVar7 + 1;
          *puVar8 = *puVar7;
          *puVar7 = 0;
          uVar1 = DAT_004aa394;
          puVar8 = puVar8 + 1;
          puVar7 = puVar6;
        } while ((int)puVar6 < 0x5a4a6c);
        *(undefined4 *)(&player_vision_distance + iVar4) = DAT_004aa390;
        DAT_005a4a80 = 0;
        *(undefined4 *)(&DAT_0081c024 + iVar4) = uVar1;
      }
      if (iVar9 < 0) {
        game_clear_player_control(1);
      }
      else {
        dVar2 = (double)CONCAT44(_DAT_005a4a94,_DAT_005a4a90);
        _DAT_005a4a90 = 0;
        _DAT_005a4a94 = 0;
        iVar5 = iVar9 * 0x3510;
        (&srcplayer_flags)[iVar9 * 0xd44] =
             (&srcplayer_flags)[iVar9 * 0xd44] ^
             (player_2_options ^ (&srcplayer_flags)[iVar9 * 0xd44]) & 0x11d400;
        (&DAT_0081c380)[iVar9 * 0xd44] = p2_input_setting;
        uVar1 = DAT_004ac080;
        (&weapon_flags_misc)[iVar9 * 0xd44] = DAT_005a4a84;
        fVar3 = FLOAT_004ac084;
        *(undefined4 *)(&DAT_0081c404 + iVar5) = 0xffffffff;
        *(undefined4 *)(&player_external_dmgflag1 + iVar5) = uVar1;
        *(float *)(&player_external_dmgflag2 + iVar5) = fVar3;
        puVar7 = &p2_control_array;
        puVar8 = &player_mvmt_flags + iVar9 * 0xd44;
        (&DAT_0081bf78)[iVar9 * 0x6a2] = dVar2 + (double)(&DAT_0081bf78)[iVar9 * 0x6a2];
        dVar2 = (double)CONCAT44(_DAT_005a4aa4,_DAT_005a4aa0);
        _DAT_005a4aa0 = 0;
        _DAT_005a4aa4 = 0;
        (&DAT_0081bf80)[iVar9 * 0x6a2] = dVar2 + (double)(&DAT_0081bf80)[iVar9 * 0x6a2];
        do {
          uVar1 = *puVar7;
          *puVar7 = 0;
          *puVar8 = uVar1;
          uVar1 = DAT_004aa39c;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        } while ((int)puVar7 < 0x5a49d4);
        *(undefined4 *)(&player_vision_distance + iVar5) = DAT_004aa398;
        DAT_005a4a84 = 0;
        *(undefined4 *)(&DAT_0081c024 + iVar5) = uVar1;
      }
    }
    else {
      if (-1 < src_player1) {
        (&DAT_0081c380)[src_player1 * 0xd44] = 0;
        (&weapon_flags_misc)[iVar5 * 0xd44] = 0;
        puVar8 = &player_mvmt_flags + iVar5 * 0xd44;
        for (iVar4 = 0x1f; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar8 = 0;
          puVar8 = puVar8 + 1;
        }
      }
      if (-1 < iVar9) {
        (&DAT_0081c380)[iVar9 * 0xd44] = 0;
        (&weapon_flags_misc)[iVar9 * 0xd44] = 0;
        puVar8 = &player_mvmt_flags + iVar9 * 0xd44;
        for (iVar5 = 0x1f; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = 0;
          puVar8 = puVar8 + 1;
        }
      }
      iVar5 = 0;
      do {
        *(undefined4 *)((int)&p1_control_array + iVar5) = 0;
        *(undefined4 *)((int)&p2_control_array + iVar5) = 0;
        iVar5 = iVar5 + 4;
      } while (iVar5 < 0x7c);
      p1_input_setting = 0;
      p2_input_setting = 0;
    }
    if (side_screen != 2) {
      engine_sync_moving_objects(game_ticks);
      just_a_ret();
      interpolate_ticks(game_ticks);
      iVar5 = 0;
      piVar10 = &tank_screen;
      do {
        if (*piVar10 != 0) {
          tweak_rpv_function(iVar5,game_ticks);
        }
        piVar10 = piVar10 + 0xd44;
        iVar5 = iVar5 + 1;
      } while ((int)piVar10 < 0x836ad0);
      sync_sprites();
      synch_doors(game_ticks);
      synch_lifts(game_ticks);
    }
    iVar5 = 0;
    piVar10 = &tank_screen;
    do {
      if (*piVar10 != 0) {
        win_init_things(iVar5,game_ticks);
      }
      piVar10 = piVar10 + 0xd44;
      iVar5 = iVar5 + 1;
    } while ((int)piVar10 < 0x836ad0);
    if (side_screen != 2) {
      sprite_time_slice(game_ticks);
      script_if_results = 0;
      do_events();
      net_start_level_script(game_ticks);
      if (DAT_0062cad8 != 0) {
        FUN_00469bc0(game_ticks);
      }
      update_game_time(game_ticks);
    }
  }
  if ((game_hostmode == 2) || (game_hostmode == 3)) {
    iVar5 = sync_game_to_server(game_ticks,0);
    net_game_action = (uint)(iVar5 != 0);
  }
  synch_sounds();
  refresh_screen();
  if (setting_on != 0) {
    init_sound_loop(LevelTicksTotal);
  }
  clear_lasers();
  return;
}

void level_briefing(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  byte bVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  char *pcVar11;
  undefined4 *puVar12;
  bool bVar13;
  uint local_24;
  undefined4 local_20;
  undefined2 local_1c;
  undefined local_1a;
  
  if (game_hostmode == 0) {
    mp_game_flags = mp_game_flags | 0x40;
  }
  if ((_DAT_004bc748 != 0) && (in_rpv == 0)) {
    _DAT_004bc748 = 0;
    if (dynamic_cam_on == 0) {
      pcVar5 = (&PTR_DAT_004bc288)[border_size];
    }
    else {
      pcVar5 = s_humpan_004bce0c;
    }
    load_panel(pcVar5);
    adjust_static_art_to_res();
  }
  if (menu_visible != 7) {
    if ((menu_visible == 3) && (iVar6 = deathmatch_game(), iVar6 != 0)) {
      get_player_mp_stats();
      menu_prep_help_screen();
      DAT_0068ccec = (uint)(DAT_0068ccec == 0);
      return;
    }
    if ((menu_visible == 3) && (DAT_0068cce4 == 0)) {
      local_20 = DAT_004ab6d4;
      local_1c = DAT_004ab6d8;
      local_20._0_1_ = (char)DAT_004ab6d4;
      DAT_0068cce4 = 1;
      DAT_0068cd94 = 0;
      DAT_0068cc8c = 0;
      _DAT_0068cc88 = 0;
      bVar13 = true;
      local_1a = DAT_004ab6da;
      if ((char)local_20 != '\0') {
        iVar6 = 0;
        do {
          if (!bVar13) goto LAB_0048f10d;
          iVar7 = get_sme_file((&level_loaded_num)[iVar6]);
          bVar13 = *(char *)((int)&local_20 + iVar6) == iVar7;
          iVar7 = iVar6 + 1;
          iVar6 = iVar6 + 1;
        } while (*(char *)((int)&local_20 + iVar7) != '\0');
      }
      if (bVar13) {
        _sprintf(&local_20,s_SML_BRIEF_LEVEL_ld_SML_004bde64,next_level_num);
      }
      else {
LAB_0048f10d:
        if (DAT_006e93ec == 1) {
          _sprintf(&local_20,s_SML_BRIEF_LEVEL_ld_SML_004bde64,next_level_num + -1);
        }
        else {
          _sprintf(&local_20,s_SML_BRIEF_LEVEL_ld_c_SML_004bde48,next_level_num + -1,
                   DAT_006e93ec + 0x60);
        }
      }
      switch(DAT_0083d62c) {
      case 0:
      case 2:
        s_Soldier_004bc2b8._0_4_ = s_Private_004bdbd0._0_4_;
        s_Soldier_004bc2b8._4_4_ = s_Private_004bdbd0._4_4_;
        break;
      default:
        s_Soldier_004bc2b8._0_4_ = s_First_Seaman_004bdd14._0_4_;
        s_Soldier_004bc2b8._4_4_ = s_First_Seaman_004bdd14._4_4_;
        _DAT_004bc2c0 = s_First_Seaman_004bdd14._8_4_;
        DAT_004bc2c4 = s_First_Seaman_004bdd14[12];
        break;
      case 4:
        s_Soldier_004bc2b8._0_4_ = s_Corporal_004bdbc4._0_4_;
        s_Soldier_004bc2b8._4_4_ = s_Corporal_004bdbc4._4_4_;
        _DAT_004bc2c0 = _DAT_004bc2c0 & 0xffffff00 | (uint)(byte)s_Corporal_004bdbc4[8];
        break;
      case 6:
        s_Soldier_004bc2b8._0_4_ = s_Lieutenant_004bdbb8._0_4_;
        s_Soldier_004bc2b8._4_4_ = s_Lieutenant_004bdbb8._4_4_;
        _DAT_004bc2c0 = CONCAT12(s_Lieutenant_004bdbb8[10],s_Lieutenant_004bdbb8._8_2_);
        _DAT_004bc2c0 = _DAT_004bc2c0 & 0xff000000 | (uint)_DAT_004bc2c0;
        break;
      case 8:
        s_Soldier_004bc2b8._0_4_ = s_Captain_004bdbb0._0_4_;
        s_Soldier_004bc2b8._4_4_ = s_Captain_004bdbb0._4_4_;
        break;
      case 10:
        s_Soldier_004bc2b8._0_4_ = s_Major_004bdba8._0_4_;
        s_Soldier_004bc2b8._4_4_ =
             s_Soldier_004bc2b8._4_4_ & 0xffff0000 | (uint)s_Major_004bdba8._4_2_;
      }
      iVar6 = open_sml(&local_20);
      if (iVar6 < 0) {
        log_message(s_Mission_objective_file__s_not_lo_004bde20,&local_20);
        DAT_0068cce0 = 0;
      }
      else {
        DAT_0068cce0 = 1;
      }
    }
    else if ((menu_visible != 3) && (DAT_0068cce4 != 0)) {
      DAT_0068cce4 = 0;
      DAT_0068cce0 = 0;
      alloc_for_sml();
    }
    if (_DAT_0068ccb0 == 0) {
      DAT_0068ccac = 0;
    }
    _DAT_0068ccb0 = 0;
    if ((menu_visible != 0) && ((menu_visible != 3 || (iVar6 = multiplayer_game(), iVar6 == 0)))) {
      if ((menu_visible == 0x25) && (DAT_00678140 < LevelTicksTotal)) {
        menu_visible = 0xc;
        DAT_0068ccf4 = DAT_00660788;
        load_into_game(DAT_00678180);
      }
      if ((menu_visible == 0x18) || (menu_visible == 0x19)) {
        iVar6 = adjust_string_00405b20
                          (&player_name + (menu_visible + -0x18) * 0x11,0xb,&DAT_00683f90);
        if (iVar6 == -1) {
          menu_visible = 1;
        }
        else {
          if (iVar6 == 0) {
            name_player_menu(menu_visible + -0x18);
            return;
          }
          if (iVar6 == 1) {
            if ((&player_name)[(menu_visible + -0x18) * 0x11] == '\0') {
              pcVar5 = (char *)generate_random_name();
              uVar8 = 0xffffffff;
              do {
                pcVar11 = pcVar5;
                if (uVar8 == 0) break;
                uVar8 = uVar8 - 1;
                pcVar11 = pcVar5 + 1;
                cVar1 = *pcVar5;
                pcVar5 = pcVar11;
              } while (cVar1 != '\0');
              uVar8 = ~uVar8;
              puVar10 = (undefined4 *)(pcVar11 + -uVar8);
              puVar12 = (undefined4 *)(&player_name + (menu_visible + -0x18) * 0x11);
              for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
                *puVar12 = *puVar10;
                puVar10 = puVar10 + 1;
                puVar12 = puVar12 + 1;
              }
              for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                *(undefined *)puVar12 = *(undefined *)puVar10;
                puVar10 = (undefined4 *)((int)puVar10 + 1);
                puVar12 = (undefined4 *)((int)puVar12 + 1);
              }
            }
            else {
              iVar6 = strcmp(&player_name + (menu_visible + -0x18) * 0x11,s_WREN_004bde10);
              uVar2 = s_THE_KNIFE_004bde04._4_4_;
              if (iVar6 == 0) {
                iVar6 = (menu_visible + -0x18) * 0x11;
                *(undefined4 *)(&player_name + iVar6) = s_THE_KNIFE_004bde04._0_4_;
                uVar3 = s_THE_KNIFE_004bde04._8_2_;
                *(undefined4 *)(iVar6 + 0x682f64) = uVar2;
                *(undefined2 *)(iVar6 + 0x682f68) = uVar3;
              }
              else {
                iVar6 = strcmp(&player_name + (menu_visible + -0x18) * 0x11,s_SPHINXX_004bddfc);
                uVar3 = s_SPHINX_004bddf4._4_2_;
                if (iVar6 == 0) {
                  iVar6 = (menu_visible + -0x18) * 0x11;
                  *(undefined4 *)(&player_name + iVar6) = s_SPHINX_004bddf4._0_4_;
                  cVar1 = s_SPHINX_004bddf4[6];
                  *(undefined2 *)(iVar6 + 0x682f64) = uVar3;
                  *(char *)(iVar6 + 0x682f66) = cVar1;
                }
                else {
                  iVar6 = strcmp(&player_name + (menu_visible + -0x18) * 0x11,s_SPHINX_004bddf4);
                  uVar2 = s_WANNA_BE_004bdde8._4_4_;
                  if (iVar6 == 0) {
                    iVar6 = (menu_visible + -0x18) * 0x11;
                    *(undefined4 *)(&player_name + iVar6) = s_WANNA_BE_004bdde8._0_4_;
                    cVar1 = s_WANNA_BE_004bdde8[8];
                    *(undefined4 *)(iVar6 + 0x682f64) = uVar2;
                    *(char *)(iVar6 + 0x682f68) = cVar1;
                  }
                }
              }
            }
            if (menu_visible == 0x18) {
              grab_flag_for_briefing();
              menu_visible = 0x1c;
              FUN_00498ae0(9,0xc4,0,LevelTicksTotal,0x1b,&play_selectm);
              flag_select_menu(0);
              return;
            }
            menu_visible = 0x1d;
            FUN_00498ae0(9,0xc4,0,LevelTicksTotal,0x1b,&play_selectm);
            flag_select_menu(1);
            return;
          }
        }
      }
      else if (menu_visible == 0x1f) {
        iVar6 = adjust_string_00405b20(&DAT_006c2058 + DAT_0068cd7c * 0x108,0x10,&DAT_00661770);
        uVar3 = s_SET_X_004bde18._4_2_;
        if (iVar6 == -1) {
          menu_visible = 1;
          _strncpy(&DAT_006c2058 + DAT_0068cd7c * 0x108,s_NEW_SET_004bdd3c,0x10);
          return;
        }
        if (iVar6 == 0) {
          key_set_save_menu(DAT_0068cd7c);
          return;
        }
        if (iVar6 == 1) {
          iVar6 = DAT_0068cd7c * 0x108;
          if ((&DAT_006c2058)[DAT_0068cd7c * 0x108] == '\0') {
            *(undefined4 *)(&DAT_006c2058 + iVar6) = s_SET_X_004bde18._0_4_;
            *(undefined2 *)(&DAT_006c205c + iVar6) = uVar3;
          }
          DAT_004bc5d4 = DAT_004bc5d4 + 1;
          if (DAT_004bc5d4 < 0x10) {
            copy_menu_text(&DAT_006c1f60 + DAT_004bc5d4 * 0x108,&DAT_004bc5d8,0x1f);
            screen_fill_memory(&DAT_006c1fdc + DAT_004bc5d4 * 0x108,0,0x1f);
            _strncpy(&DAT_006c2058 + DAT_004bc5d4 * 0x108,s_NEW_SET_004bdd3c,0x10);
          }
          menu_visible = 0x22;
          FUN_00498ae0(9,0xc4,0,LevelTicksTotal,0x1b,&play_selectm);
          keyboard_setup_menu(DAT_0068cd7c);
          return;
        }
      }
      else {
        if (menu_visible == 0x1a) {
          iVar6 = 0;
          do {
            get_input_config(iVar6);
            iVar6 = iVar6 + 1;
          } while (iVar6 < 8);
        }
        bVar4 = script_exit();
        local_24 = local_24 & 0xffffff00 | (uint)bVar4;
        if (bVar4 != 0) {
          do {
            main_menu_logic(local_24);
            bVar4 = script_exit();
            local_24 = local_24 & 0xffffff00 | (uint)bVar4;
          } while (bVar4 != 0);
          return;
        }
      }
    }
  }
  return;
}
