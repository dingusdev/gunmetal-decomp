void script_run_main(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                    int param_6,int param_7,int param_8,uint param_9)

{
  double dVar1;
  byte bVar2;
  double dVar3;
  double dVar4;
  bool bVar5;
  undefined *puVar6;
  char cVar7;
  undefined4 uVar8;
  int select_sec;
  undefined2 *puVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  uint uVar15;
  int *piVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  script_command **ppsVar20;
  int iVar21;
  uint *puVar22;
  int iVar23;
  int *piVar24;
  int iVar25;
  int *piVar26;
  undefined *puVar27;
  char *pcVar28;
  undefined4 *puVar29;
  undefined4 *puVar30;
  int *piVar31;
  float10 fVar32;
  float10 fVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  undefined4 uVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  undefined4 uVar39;
  undefined4 uVar40;
  undefined4 uVar41;
  undefined4 uVar42;
  undefined4 uVar43;
  undefined4 uVar44;
  undefined4 uVar45;
  undefined4 uVar46;
  undefined4 uVar47;
  char *pcVar48;
  int local_74;
  undefined local_50 [24];
  undefined local_38 [24];
  undefined local_20 [28];
  
  select_sec = param_1;
  puVar27 = selected_poly;
  if (param_1 < 0x30000) {
    while( true ) {
      iVar21 = param_3;
      bVar2 = puVar27[select_sec];
      if (bVar2 == 0xff) break;
      if (bVar2 == 0xc9) {
        param_1 = select_sec + 1;
        script_run_sos(&param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,&param_9);
        select_sec = param_1;
        puVar27 = selected_poly;
        goto LAB_0045c41b;
      }
      bVar5 = true;
      if (game_hostmode == 1) {
        local_74 = 0;
        ppsVar20 = &PTR_DAT_004b53f8;
        do {
          if (*ppsVar20 == (script_command *)(uint)bVar2) {
            if ((&PTR_DAT_004b53f0)[local_74 * 5] == (script_command *)0x0) {
              if ((int)(&PTR_004b53f4)[local_74 * 5] < 0) {
                log_message(s_Internal_Error:_Negative_script_c_004b8640);
                select_sec = param_1;
                puVar27 = selected_poly;
              }
              else {
                param_1 = (int)&(&PTR_004b53f4)[local_74 * 5]->script_name + select_sec + 1;
                bVar5 = false;
                select_sec = param_1;
              }
            }
            break;
          }
          ppsVar20 = ppsVar20 + 5;
          local_74 = local_74 + 1;
        } while ((int)ppsVar20 < 0x4b62f8);
      }
      iVar14 = param_8;
      uVar12 = param_5;
      uVar8 = param_4;
      iVar23 = num_sec_handles;
      iVar18 = num_scripts;
      if (!bVar5) goto LAB_0045c41b;
      iVar25 = select_sec + 1;
      param_1 = iVar25;
      switch(puVar27[select_sec]) {
      case 1:
        goto switchD_004574d4_exit_event;
      case 2:
        script_fun2_generate
                  (*(undefined4 *)(puVar27 + iVar25),iVar21,param_4,param_5,param_6,param_7,param_8,
                   param_9);
        param_1 = param_1 + 4;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 3:
        uVar19 = param_9 & 0xffff;
        if ((7 < uVar19) && (uVar19 < 0x10c)) {
          select_sec = uVar19 - 8;
          iVar21 = 0;
          if (0 < *(int *)(&child_thing + select_sec * 0x528)) {
            dVar1 = (double)param_8;
            dVar3 = (double)param_7;
            dVar4 = (double)param_6;
            do {
              generate_for_thing(*(undefined4 *)(selected_poly + param_1),param_3,param_4,param_5,
                                 dVar4,dVar3,dVar1,
                                 *(int *)(&DAT_007ac398 + (iVar21 + select_sec * 0x14a) * 4) + 8 +
                                 (param_9 & 0xffff0000));
              iVar21 = iVar21 + 1;
              select_sec = (param_9 & 0xffff) - 8;
            } while (iVar21 < *(int *)(&child_thing + select_sec * 0x528));
            param_1 = param_1 + 4;
            select_sec = param_1;
            puVar27 = selected_poly;
            break;
          }
        }
        goto LAB_0045be82;
      case 4:
        uVar19 = param_9 & 0xffff;
        if (((uVar19 < 8) || (0x10b < uVar19)) || ((int)(&parent_thing)[(uVar19 - 8) * 0x14a] < 0))
        goto LAB_0045c36a;
        generate_for_thing(*(undefined4 *)(puVar27 + iVar25),iVar21,param_4,param_5,(double)param_6,
                           (double)param_7,(double)param_8,
                           (param_9 & 0xffff0000) + 8 + (&parent_thing)[(uVar19 - 8) * 0x14a]);
        goto LAB_0045bfec;
      case 5:
        iVar21 = *(int *)(puVar27 + iVar25);
        param_1 = select_sec + 5;
        iVar23 = 0;
        select_sec = param_1;
        if (0 < num_scripts) {
          do {
            if ((&compiled_scripts)[iVar23] == iVar21) {
              (&script_event_id)[iVar23] = (&script_event_id)[iVar23] | 0x1ff;
            }
            iVar23 = iVar23 + 1;
          } while (iVar23 < iVar18);
        }
        break;
      case 6:
        iVar21 = *(int *)(puVar27 + iVar25);
        param_1 = select_sec + 5;
        iVar23 = 0;
        select_sec = param_1;
        if (0 < num_scripts) {
          do {
            if ((&compiled_scripts)[iVar23] == iVar21) {
              (&script_event_id)[iVar23] = (&script_event_id)[iVar23] & 0xfffffe00;
            }
            iVar23 = iVar23 + 1;
          } while (iVar23 < iVar18);
        }
        break;
      case 7:
        iVar18 = *(int *)(puVar27 + iVar25) - param_2;
        param_1 = select_sec + 5;
        if (0 < iVar18) {
          select_sec = 0;
          piVar16 = &num_sleeping_scripts;
          do {
            if (*piVar16 < 0) {
              (&DAT_005e4278)[select_sec] = iVar18;
              (&DAT_005e5e58)[select_sec] = param_4;
              (&DAT_005e2dd8)[select_sec] = param_5;
              (&DAT_005e39d8)[select_sec] = param_6;
              (&DAT_005e35d8)[select_sec] = param_7;
              (&num_sleeping_scripts)[select_sec] = param_1;
              (&DAT_00616258)[select_sec] = iVar21;
              (&DAT_005e31d8)[select_sec] = param_8;
              (&DAT_005b29c8)[select_sec] = param_9;
              return;
            }
            piVar16 = piVar16 + 1;
            select_sec = select_sec + 1;
          } while ((int)piVar16 < 0x5e41f0);
          log_message(s_Maximum_sleeping_scripts_(%ld)_r_004b8134,0x100);
          return;
        }
        param_2 = -iVar18;
        select_sec = param_1;
        break;
      case 8:
        iVar21 = *(int *)(puVar27 + iVar25);
        if ((iVar21 < 0) || (0xff < iVar21)) {
          log_message(s_Script_run_error:_bad_set_sector_004b8600,iVar21);
          param_1 = param_1 + 0x24;
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        else {
          iVar18 = iVar21 * 0x58;
          *(double *)(&sector_mvmt_x + iVar21 * 0x16) = (double)*(int *)(puVar27 + select_sec + 5);
          *(double *)(&sector_mvmt_y + iVar21 * 0x16) = (double)*(int *)(puVar27 + select_sec + 9);
          *(double *)(&sector_mvmt_z + iVar21 * 0x16) = (double)*(int *)(puVar27 + select_sec + 0xd)
          ;
          *(undefined4 *)(&sector_move_pitch + iVar21 * 0xb) =
               *(undefined4 *)(puVar27 + select_sec + 0x11);
          *(undefined4 *)((int)&sector_move_pitch + iVar18 + 4) =
               *(undefined4 *)(puVar27 + select_sec + 0x15);
          *(undefined4 *)(&sector_move_roll + iVar21 * 0xb) =
               *(undefined4 *)(puVar27 + select_sec + 0x19);
          *(undefined4 *)((int)&sector_move_roll + iVar18 + 4) =
               *(undefined4 *)(puVar27 + select_sec + 0x1d);
          param_1 = select_sec + 0x29;
          *(undefined4 *)(&sector_move_yaw + iVar21 * 0xb) =
               *(undefined4 *)(puVar27 + select_sec + 0x21);
          *(undefined4 *)((int)&sector_move_yaw + iVar18 + 4) =
               *(undefined4 *)(puVar27 + select_sec + 0x25);
          select_sec = param_1;
        }
        break;
      case 9:
        select_sec = set_sector_brightness(*(undefined4 *)(puVar27 + iVar25));
        if (select_sec == 0) {
          puVar30 = (undefined4 *)(selected_poly + param_1);
          param_1 = param_1 + 4;
          log_message(s_Script_run_error:_unable_to_obta_004b85cc,*puVar30);
          param_1 = param_1 + 4;
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        else {
          *(undefined *)(select_sec + 0x16) = selected_poly[param_1 + 4];
          param_1 = param_1 + 8;
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        break;
      case 10:
        param_1 = select_sec + 5;
        set_sector_type(*(undefined4 *)(puVar27 + iVar25),*(undefined4 *)(puVar27 + param_1));
        param_1 = param_1 + 4;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0xb:
        iVar21 = *(int *)(puVar27 + iVar25);
        uVar19 = *(uint *)(puVar27 + select_sec + 5);
        select_sec = select_sec + 9;
        param_1 = select_sec;
        if ((-1 < iVar21) && (iVar21 < 0x100)) {
          (&sec_standard_damage)[iVar21 * 0x16] = uVar19 & 0xffff;
          (&sec_internal_damage)[iVar21 * 0x16] = (int)uVar19 >> 0x10;
        }
        break;
      case 0xc:
        set_sector_sound(*(undefined4 *)(puVar27 + iVar25),*(undefined4 *)(puVar27 + select_sec + 9)
                         ,*(undefined4 *)(puVar27 + select_sec + 5),
                         *(undefined4 *)(puVar27 + select_sec + 0xd),
                         *(undefined4 *)(puVar27 + select_sec + 0x11));
        param_1 = param_1 + 0x14;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0xd:
        iVar21 = *(int *)(puVar27 + iVar25);
        iVar25 = select_sec + 5;
        if ((iVar21 < 0) || (0xff < iVar21)) goto LAB_0045c3f6;
        param_1 = select_sec + 0xd;
        (&sec_enter_ev)[iVar21 * 0x16] = *(undefined4 *)(puVar27 + iVar25);
        (&sec_exit_ev)[iVar21 * 0x16] = *(undefined4 *)(puVar27 + select_sec + 9);
        select_sec = param_1;
        break;
      case 0xe:
        iVar21 = *(int *)(puVar27 + iVar25);
        iVar25 = select_sec + 5;
        if ((iVar21 < 0) || (0xff < iVar21)) goto LAB_0045c36a;
        param_1 = select_sec + 9;
        (&src_sector_flags)[iVar21 * 0x16] = *(undefined4 *)(puVar27 + select_sec + 5);
        select_sec = param_1;
        break;
      case 0xf:
        puVar9 = (undefined2 *)
                 obtain_poly(*(undefined4 *)(puVar27 + iVar25),
                             *(undefined4 *)(puVar27 + select_sec + 5),
                             *(undefined4 *)(puVar27 + select_sec + 9));
        if (puVar9 == (undefined2 *)0x0) {
LAB_00457ab1:
          log_message(s_Script_run_error:_unable_to_obta_004b8594,
                      *(undefined4 *)(selected_poly + param_1),
                      *(undefined4 *)(selected_poly + param_1 + 4),
                      *(undefined4 *)(selected_poly + param_1 + 8));
          param_1 = param_1 + 0x10;
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        else {
          *puVar9 = *(undefined2 *)(selected_poly + param_1 + 0xc);
          param_1 = param_1 + 0x10;
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        break;
      case 0x10:
        select_sec = obtain_poly(*(undefined4 *)(puVar27 + iVar25),
                                 *(undefined4 *)(puVar27 + select_sec + 5),
                                 *(undefined4 *)(puVar27 + select_sec + 9));
        if (select_sec == 0) goto LAB_00457ab1;
        *(undefined *)(select_sec + 0x70) = selected_poly[param_1 + 0xc];
        param_1 = param_1 + 0x10;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0x11:
        select_sec = obtain_poly(*(undefined4 *)(puVar27 + iVar25),
                                 *(undefined4 *)(puVar27 + select_sec + 5),
                                 *(undefined4 *)(puVar27 + select_sec + 9));
        if (select_sec == 0) {
          log_message(s_Script_run_error:_unable_to_obta_004b8594,
                      *(undefined4 *)(selected_poly + param_1),
                      *(undefined4 *)(selected_poly + param_1 + 4),
                      *(undefined4 *)(selected_poly + param_1 + 8));
          param_1 = param_1 + 0x1c;
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        else {
          set_poly_scroll(select_sec,gm_mem_loc - param_2);
          *(undefined2 *)(select_sec + 0x5c) = *(undefined2 *)(selected_poly + param_1 + 0xc);
          *(undefined2 *)(select_sec + 0x60) = *(undefined2 *)(selected_poly + param_1 + 0x10);
          param_1 = param_1 + 0x1c;
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        break;
      case 0x12:
        log_message(puVar27 + iVar25);
        goto LAB_00457baf;
      case 0x13:
        exit_program();
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0x14:
        if (setting_on == 0) goto LAB_0045aea9;
        play_sample(*(undefined4 *)(puVar27 + iVar25),*(undefined4 *)(puVar27 + select_sec + 5),
                    *(undefined4 *)(puVar27 + select_sec + 9),
                    *(undefined4 *)(puVar27 + select_sec + 0xd),
                    *(undefined4 *)(puVar27 + select_sec + 0x11));
        select_sec = param_1 + 0x14;
        puVar27 = selected_poly;
        param_1 = param_1 + 0x14;
        break;
      case 0x15:
        if (setting_on != 0) {
          play_sample_at_location
                    (*(undefined4 *)(puVar27 + iVar25),*(undefined4 *)(puVar27 + select_sec + 5),
                     *(undefined4 *)(puVar27 + select_sec + 9),
                     *(undefined4 *)(puVar27 + select_sec + 0xd),
                     *(undefined4 *)(puVar27 + select_sec + 0x11),
                     *(undefined4 *)(puVar27 + select_sec + 0x15),
                     *(undefined4 *)(puVar27 + select_sec + 0x19));
          puVar27 = selected_poly;
        }
        goto LAB_0045a5fc;
      case 0x16:
        log_message(s_Script_command_SPEAK_NUMBER_is_c_004b854c);
        param_1 = param_1 + 4;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0x17:
        if ((setting_on != 0) && (DAT_004aac7c != 0)) {
          speak_sample(*(undefined4 *)(puVar27 + iVar25),*(undefined4 *)(puVar27 + select_sec + 5),
                       *(undefined4 *)(puVar27 + select_sec + 9),
                       *(undefined4 *)(puVar27 + select_sec + 0xd));
          goto LAB_00457f63;
        }
LAB_0045b406:
        select_sec = iVar25 + 0x10;
        param_1 = iVar25 + 0x10;
        break;
      case 0x18:
        set_sourceworldobject_hit_off(iVar21,param_4);
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0x19:
        set_sourceworldobject_hit_on(iVar21,param_4);
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0x1a:
        set_sourceworldobject_textures
                  (iVar21,param_4,*(undefined4 *)(puVar27 + iVar25),gm_mem_loc - param_2);
        param_1 = param_1 + 4;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0x1b:
        if ((iVar21 < 0) || (0xff < iVar21)) goto LAB_0045899a;
        iVar18 = iVar21 * 0x58;
        *(double *)(&sector_mvmt_x + iVar21 * 0x16) = (double)*(int *)(puVar27 + iVar25);
        *(double *)(&sector_mvmt_y + iVar21 * 0x16) = (double)*(int *)(puVar27 + select_sec + 5);
        *(double *)(&sector_mvmt_z + iVar21 * 0x16) = (double)*(int *)(puVar27 + select_sec + 9);
        *(undefined4 *)(&sector_move_pitch + iVar21 * 0xb) =
             *(undefined4 *)(puVar27 + select_sec + 0xd);
        *(undefined4 *)((int)&sector_move_pitch + iVar18 + 4) =
             *(undefined4 *)(puVar27 + select_sec + 0x11);
        *(undefined4 *)(&sector_move_roll + iVar21 * 0xb) =
             *(undefined4 *)(puVar27 + select_sec + 0x15);
        *(undefined4 *)((int)&sector_move_roll + iVar18 + 4) =
             *(undefined4 *)(puVar27 + select_sec + 0x19);
        param_1 = select_sec + 0x25;
        *(undefined4 *)(&sector_move_yaw + iVar21 * 0xb) =
             *(undefined4 *)(puVar27 + select_sec + 0x1d);
        *(undefined4 *)((int)&sector_move_yaw + iVar18 + 4) =
             *(undefined4 *)(puVar27 + select_sec + 0x21);
        select_sec = param_1;
        break;
      case 0x1c:
        select_sec = set_sector_brightness(iVar21);
        if (select_sec == 0) {
          log_message(s_Script_run_error:_unable_to_obta_004b85cc,iVar21);
          param_1 = param_1 + 4;
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        else {
          *(undefined *)(select_sec + 0x16) = selected_poly[param_1];
          param_1 = param_1 + 4;
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        break;
      case 0x1d:
        if ((iVar21 < 0) || (0xff < iVar21)) goto LAB_0045c36a;
        select_sec = select_sec + 5;
        (&src_sector_flags)[iVar21 * 0x16] = *(undefined4 *)(puVar27 + iVar25);
        param_1 = select_sec;
        break;
      case 0x1e:
        if ((iVar21 < 0) || (0xff < iVar21)) goto LAB_0045c36a;
        set_sector_type(iVar21,*(undefined4 *)(puVar27 + iVar25));
        goto LAB_0045bfec;
      case 0x1f:
        uVar19 = *(uint *)(puVar27 + iVar25);
        select_sec = select_sec + 5;
        param_1 = select_sec;
        if ((-1 < iVar21) && (iVar21 < 0x100)) {
          (&sec_standard_damage)[iVar21 * 0x16] = uVar19 & 0xffff;
          (&sec_internal_damage)[iVar21 * 0x16] = (int)uVar19 >> 0x10;
        }
        break;
      case 0x20:
        puVar9 = (undefined2 *)obtain_poly(iVar21,param_4,param_5);
        if (puVar9 == (undefined2 *)0x0) {
LAB_004581dd:
          log_message(s_Script_run_error:_unable_to_obta_004b8594,iVar21,uVar8,uVar12);
          param_1 = param_1 + 4;
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        else {
          *puVar9 = *(undefined2 *)(selected_poly + param_1);
          param_1 = param_1 + 4;
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        break;
      case 0x21:
        select_sec = obtain_poly(iVar21,param_4,param_5);
        if (select_sec == 0) goto LAB_004581dd;
        *(undefined *)(select_sec + 0x70) = selected_poly[param_1];
        param_1 = param_1 + 4;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0x22:
        select_sec = obtain_poly(iVar21,param_4,param_5);
        if (select_sec == 0) goto LAB_004581dd;
        *(undefined2 *)(select_sec + 2) = *(undefined2 *)(selected_poly + param_1);
        param_1 = param_1 + 4;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0x23:
        select_sec = obtain_poly(iVar21,param_4,param_5);
        if (select_sec == 0) {
          log_message(s_Script_run_error:_unable_to_obta_004b8594,iVar21,param_4,uVar12);
          param_1 = param_1 + 0x10;
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        else {
          set_poly_scroll(select_sec,gm_mem_loc - param_2);
          *(undefined2 *)(select_sec + 0x5c) = *(undefined2 *)(selected_poly + param_1);
          *(undefined2 *)(select_sec + 0x60) = *(undefined2 *)(selected_poly + param_1 + 4);
          param_1 = param_1 + 0x10;
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        break;
      case 0x24:
        set_sourcepoly_switch_event(iVar21,param_4,param_5,*(undefined4 *)(puVar27 + iVar25));
        param_1 = param_1 + 4;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0x25:
        if (setting_on == 0) goto LAB_0045b406;
        play_sample_at_location
                  (*(undefined4 *)(puVar27 + iVar25),*(undefined4 *)(puVar27 + select_sec + 5),
                   *(undefined4 *)(puVar27 + select_sec + 9),
                   *(undefined4 *)(puVar27 + select_sec + 0xd),param_6,param_7,param_8);
LAB_00457f63:
        select_sec = param_1 + 0x10;
        puVar27 = selected_poly;
        param_1 = param_1 + 0x10;
        break;
      case 0x26:
        if (setting_on == 0) {
          select_sec = select_sec + 0x15;
          param_1 = select_sec;
        }
        else {
          if (*(int *)(puVar27 + iVar25) == 0) {
            iVar21 = 0;
          }
          else {
            iVar21 = param_9 << 0x10;
          }
          param_1 = select_sec + 9;
          select_sec = get_sample_source(iVar21 + *(int *)(puVar27 + select_sec + 5),2);
          if (-1 < select_sec) {
            play_frame_loop(*(undefined4 *)(selected_poly + param_1),select_sec,
                            *(undefined4 *)(selected_poly + param_1 + 4),0x2b11,
                            *(undefined4 *)(selected_poly + param_1 + 8),param_6,param_7,param_8);
          }
          select_sec = param_1 + 0xc;
          puVar27 = selected_poly;
          param_1 = param_1 + 0xc;
        }
        break;
      case 0x27:
        uVar19 = (int)param_9 >> 0x10 & 0xffff;
        select_sec = iVar25;
        if ((0x10b < uVar19) && (uVar19 < 0x238)) {
          remove_src_item(uVar19 - 0x10c);
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        break;
      case 0x28:
        iVar21 = *(int *)(puVar27 + iVar25);
        iVar25 = select_sec + 5;
        iVar18 = 0;
        if (num_sec_handles < 1) goto LAB_0045899a;
        do {
          if (iVar21 == (&DAT_005b1df8)[iVar18]) {
            iVar23 = (&script_sec_num)[iVar18];
            iVar14 = iVar23 * 0x58;
            *(double *)(&sector_mvmt_x + iVar23 * 0x16) = (double)*(int *)(puVar27 + iVar25);
            *(double *)(&sector_mvmt_y + iVar23 * 0x16) = (double)*(int *)(puVar27 + select_sec + 9)
            ;
            *(double *)(&sector_mvmt_z + iVar23 * 0x16) =
                 (double)*(int *)(puVar27 + select_sec + 0xd);
            *(undefined4 *)(&sector_move_pitch + iVar23 * 0xb) =
                 *(undefined4 *)(puVar27 + select_sec + 0x11);
            *(undefined4 *)((int)&sector_move_pitch + iVar14 + 4) =
                 *(undefined4 *)(puVar27 + select_sec + 0x15);
            *(undefined4 *)(&sector_move_roll + iVar23 * 0xb) =
                 *(undefined4 *)(puVar27 + select_sec + 0x19);
            *(undefined4 *)((int)&sector_move_roll + iVar14 + 4) =
                 *(undefined4 *)(puVar27 + select_sec + 0x1d);
            *(undefined4 *)(&sector_move_yaw + iVar23 * 0xb) =
                 *(undefined4 *)(puVar27 + select_sec + 0x21);
            *(undefined4 *)((int)&sector_move_yaw + iVar14 + 4) =
                 *(undefined4 *)(puVar27 + select_sec + 0x25);
          }
          iVar18 = iVar18 + 1;
        } while (iVar18 < num_sec_handles);
        select_sec = select_sec + 0x29;
        param_1 = select_sec;
        break;
      case 0x29:
        iVar21 = *(int *)(puVar27 + iVar25);
        iVar25 = select_sec + 5;
        select_sec = 0;
        param_1 = iVar25;
        if (num_sec_handles < 1) goto LAB_0045c36a;
        do {
          if (iVar21 == (&DAT_005b1df8)[select_sec]) {
            iVar18 = set_sector_brightness((&script_sec_num)[select_sec]);
            if (iVar18 == 0) {
              log_message(s_Script_run_error:_unable_to_obta_004b85cc,(&script_sec_num)[select_sec])
              ;
              iVar25 = param_1;
              puVar27 = selected_poly;
            }
            else {
              *(undefined *)(iVar18 + 0x16) = selected_poly[param_1];
              iVar25 = param_1;
              puVar27 = selected_poly;
            }
          }
          select_sec = select_sec + 1;
        } while (select_sec < num_sec_handles);
        select_sec = iVar25 + 4;
        param_1 = iVar25 + 4;
        break;
      case 0x2a:
        iVar21 = *(int *)(puVar27 + iVar25);
        iVar25 = select_sec + 5;
        select_sec = 0;
        param_1 = iVar25;
        if (num_sec_handles < 1) goto LAB_0045c36a;
        do {
          if (iVar21 == (&DAT_005b1df8)[select_sec]) {
            set_sector_type((&script_sec_num)[select_sec],*(undefined4 *)(puVar27 + iVar25));
            iVar25 = param_1;
            puVar27 = selected_poly;
          }
          select_sec = select_sec + 1;
        } while (select_sec < num_sec_handles);
        select_sec = iVar25 + 4;
        param_1 = iVar25 + 4;
        break;
      case 0x2b:
        iVar21 = *(int *)(puVar27 + iVar25);
        iVar25 = select_sec + 5;
        iVar18 = 0;
        if (num_sec_handles < 1) goto LAB_0045c36a;
        do {
          if (iVar21 == (&DAT_005b1df8)[iVar18]) {
            iVar23 = (&script_sec_num)[iVar18];
            (&sec_standard_damage)[iVar23 * 0x16] = *(uint *)(puVar27 + iVar25) & 0xffff;
            (&sec_internal_damage)[iVar23 * 0x16] = *(int *)(puVar27 + iVar25) >> 0x10;
          }
          iVar18 = iVar18 + 1;
        } while (iVar18 < num_sec_handles);
        select_sec = select_sec + 9;
        param_1 = select_sec;
        break;
      case 0x2c:
        iVar21 = *(int *)(puVar27 + iVar25);
        iVar25 = select_sec + 5;
        iVar18 = 0;
        if (num_sec_handles < 1) goto LAB_0045c36a;
        do {
          if (iVar21 == (&DAT_005b1df8)[iVar18]) {
            (&src_sector_flags)[(&script_sec_num)[iVar18] * 0x16] =
                 *(undefined4 *)(puVar27 + iVar25);
          }
          iVar18 = iVar18 + 1;
        } while (iVar18 < iVar23);
        select_sec = select_sec + 9;
        param_1 = select_sec;
        break;
      case 0x2d:
        iVar21 = *(int *)(puVar27 + iVar25);
        iVar25 = select_sec + 5;
        select_sec = 0;
        param_1 = iVar25;
        if (num_sec_handles < 1) goto LAB_0045b406;
        do {
          if (iVar21 == (&DAT_005b1df8)[select_sec]) {
            set_sector_sound((&script_sec_num)[select_sec],*(undefined4 *)(puVar27 + iVar25),
                             *(undefined4 *)(puVar27 + iVar25 + 4),
                             *(undefined4 *)(puVar27 + iVar25 + 8),
                             *(undefined4 *)(puVar27 + iVar25 + 0xc));
            iVar25 = param_1;
            puVar27 = selected_poly;
          }
          select_sec = select_sec + 1;
        } while (select_sec < num_sec_handles);
        select_sec = iVar25 + 0x10;
        param_1 = iVar25 + 0x10;
        break;
      case 0x2e:
        iVar21 = *(int *)(puVar27 + iVar25);
        iVar25 = select_sec + 5;
        select_sec = 0;
        if (num_poly_handles < 1) goto LAB_0045c36a;
        puVar30 = &poly_handle;
        puVar29 = &poly_handle_texture;
        param_1 = iVar25;
        do {
          if (iVar21 == (&select_poly_handle)[select_sec]) {
            puVar9 = (undefined2 *)obtain_poly(*puVar30,*puVar29,(&script_ref_poly)[select_sec]);
            if (puVar9 == (undefined2 *)0x0) {
              log_message(s_Script_run_error:_unable_to_obta_004b8594,*puVar30,*puVar29,
                          (&script_ref_poly)[select_sec]);
              iVar25 = param_1;
              puVar27 = selected_poly;
            }
            else {
              *puVar9 = *(undefined2 *)(selected_poly + param_1);
              iVar25 = param_1;
              puVar27 = selected_poly;
            }
          }
          select_sec = select_sec + 1;
          puVar29 = puVar29 + 1;
          puVar30 = puVar30 + 1;
        } while (select_sec < num_poly_handles);
        select_sec = iVar25 + 4;
        param_1 = iVar25 + 4;
        break;
      case 0x2f:
        iVar21 = *(int *)(puVar27 + iVar25);
        iVar25 = select_sec + 5;
        select_sec = 0;
        if (num_poly_handles < 1) goto LAB_0045c36a;
        puVar30 = &poly_handle;
        puVar29 = &poly_handle_texture;
        param_1 = iVar25;
        do {
          if (iVar21 == (&select_poly_handle)[select_sec]) {
            iVar18 = obtain_poly(*puVar30,*puVar29,(&script_ref_poly)[select_sec]);
            if (iVar18 == 0) {
              log_message(s_Script_run_error:_unable_to_obta_004b8594,*puVar30,*puVar29,
                          (&script_ref_poly)[select_sec]);
              iVar25 = param_1;
              puVar27 = selected_poly;
            }
            else {
              *(undefined *)(iVar18 + 0x70) = selected_poly[param_1];
              iVar25 = param_1;
              puVar27 = selected_poly;
            }
          }
          select_sec = select_sec + 1;
          puVar29 = puVar29 + 1;
          puVar30 = puVar30 + 1;
        } while (select_sec < num_poly_handles);
        select_sec = iVar25 + 4;
        param_1 = iVar25 + 4;
        break;
      case 0x30:
        iVar21 = *(int *)(puVar27 + iVar25);
        iVar25 = select_sec + 5;
        select_sec = 0;
        if (num_poly_handles < 1) goto LAB_0045b406;
        puVar30 = &poly_handle;
        puVar29 = &poly_handle_texture;
        param_1 = iVar25;
        do {
          if (iVar21 == (&select_poly_handle)[select_sec]) {
            iVar18 = obtain_poly(*puVar30,*puVar29,(&script_ref_poly)[select_sec]);
            if (iVar18 == 0) {
              log_message(s_Script_run_error:_unable_to_obta_004b8594,*puVar30,*puVar29,
                          (&script_ref_poly)[select_sec]);
              iVar25 = param_1;
              puVar27 = selected_poly;
            }
            else {
              set_poly_scroll(iVar18,gm_mem_loc - param_2);
              *(undefined2 *)(iVar18 + 0x5c) = *(undefined2 *)(selected_poly + param_1);
              *(undefined2 *)(iVar18 + 0x60) = *(undefined2 *)(selected_poly + param_1 + 4);
              iVar25 = param_1;
              puVar27 = selected_poly;
            }
          }
          select_sec = select_sec + 1;
          puVar29 = puVar29 + 1;
          puVar30 = puVar30 + 1;
        } while (select_sec < num_poly_handles);
        select_sec = iVar25 + 0x10;
        param_1 = iVar25 + 0x10;
        break;
      case 0x31:
        iVar21 = *(int *)(puVar27 + iVar25);
        iVar25 = select_sec + 5;
        select_sec = 0;
        if (num_poly_handles < 1) goto LAB_0045c36a;
        puVar30 = &poly_handle;
        puVar29 = &poly_handle_texture;
        param_1 = iVar25;
        do {
          if (iVar21 == (&select_poly_handle)[select_sec]) {
            iVar18 = obtain_poly(*puVar30,*puVar29,(&script_ref_poly)[select_sec]);
            if (iVar18 == 0) {
              log_message(s_Script_run_error:_unable_to_obta_004b8594,*puVar30,*puVar29,
                          (&script_ref_poly)[select_sec]);
              iVar25 = param_1;
              puVar27 = selected_poly;
            }
            else {
              *(undefined2 *)(iVar18 + 2) = *(undefined2 *)(selected_poly + param_1);
              iVar25 = param_1;
              puVar27 = selected_poly;
            }
          }
          select_sec = select_sec + 1;
          puVar29 = puVar29 + 1;
          puVar30 = puVar30 + 1;
        } while (select_sec < num_poly_handles);
        select_sec = iVar25 + 4;
        param_1 = iVar25 + 4;
        break;
      case 0x32:
        add_screen_text(puVar27 + select_sec + 5,*(undefined4 *)(puVar27 + iVar25),0xffffffff,
                        gm_mem_loc + 0x111);
        param_1 = param_1 + 4;
        goto LAB_0045b5e3;
      case 0x33:
        add_screen_text(puVar27 + select_sec + 5,*(undefined4 *)(puVar27 + iVar25),param_9 & 0xffff,
                        gm_mem_loc + 0x111);
        param_1 = param_1 + 4;
        goto LAB_00457baf;
      case 0x34:
        uVar12 = *(undefined4 *)(puVar27 + select_sec + 0x19);
        uVar8 = *(undefined4 *)(puVar27 + select_sec + 0x15);
        uVar47 = 1;
        uVar13 = *(undefined4 *)(puVar27 + select_sec + 0x11);
        uVar45 = *(undefined4 *)(puVar27 + select_sec + 0xd);
        uVar39 = *(undefined4 *)(puVar27 + select_sec + 9);
        uVar37 = *(undefined4 *)(puVar27 + select_sec + 5);
        uVar35 = *(undefined4 *)(puVar27 + iVar25);
        goto LAB_00459a62;
      case 0x35:
        uVar12 = *(undefined4 *)(puVar27 + select_sec + 0x15);
        uVar8 = *(undefined4 *)(puVar27 + select_sec + 0x3d);
        uVar46 = 1;
        uVar13 = *(undefined4 *)(puVar27 + select_sec + 0x11);
        uVar45 = *(undefined4 *)(puVar27 + select_sec + 0xd);
        uVar39 = *(undefined4 *)(puVar27 + select_sec + 0x39);
        uVar37 = *(undefined4 *)(puVar27 + select_sec + 0x35);
        uVar35 = *(undefined4 *)(puVar27 + select_sec + 0x31);
        uVar47 = *(undefined4 *)(puVar27 + select_sec + 0x2d);
        uVar44 = *(undefined4 *)(puVar27 + select_sec + 0x29);
        uVar43 = *(undefined4 *)(puVar27 + select_sec + 0x25);
        uVar42 = *(undefined4 *)(puVar27 + select_sec + 0x21);
        uVar41 = *(undefined4 *)(puVar27 + select_sec + 0x1d);
        uVar40 = *(undefined4 *)(puVar27 + select_sec + 0x19);
        uVar38 = *(undefined4 *)(puVar27 + select_sec + 9);
        uVar36 = *(undefined4 *)(puVar27 + select_sec + 5);
        uVar34 = *(undefined4 *)(puVar27 + iVar25);
        goto LAB_004599af;
      case 0x36:
        uVar8 = *(undefined4 *)(puVar27 + select_sec + 0x15);
        uVar12 = *(undefined4 *)(puVar27 + select_sec + 0x19);
        uVar47 = 0;
        uVar13 = *(undefined4 *)(puVar27 + select_sec + 0x11);
        uVar45 = *(undefined4 *)(puVar27 + select_sec + 0xd);
        uVar39 = *(undefined4 *)(puVar27 + select_sec + 9);
        uVar37 = *(undefined4 *)(puVar27 + select_sec + 5);
        uVar35 = *(undefined4 *)(puVar27 + iVar25);
LAB_00459a62:
        script_add_item(uVar35,uVar37,uVar39,param_6,param_7,param_8,0,0,0,0,0,0,uVar45,uVar13,uVar8
                        ,uVar12,gm_mem_loc - param_2,uVar47,param_9 & 0xffff);
        param_1 = param_1 + 0x1c;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0x37:
        uVar8 = *(undefined4 *)(puVar27 + select_sec + 0x3d);
        uVar12 = *(undefined4 *)(puVar27 + select_sec + 0x15);
        uVar46 = 0;
        uVar13 = *(undefined4 *)(puVar27 + select_sec + 0x11);
        uVar45 = *(undefined4 *)(puVar27 + select_sec + 0xd);
        uVar39 = *(undefined4 *)(puVar27 + select_sec + 0x39);
        uVar37 = *(undefined4 *)(puVar27 + select_sec + 0x35);
        uVar35 = *(undefined4 *)(puVar27 + select_sec + 0x31);
        uVar47 = *(undefined4 *)(puVar27 + select_sec + 0x2d);
        uVar44 = *(undefined4 *)(puVar27 + select_sec + 0x29);
        uVar43 = *(undefined4 *)(puVar27 + select_sec + 0x25);
        uVar42 = *(undefined4 *)(puVar27 + select_sec + 0x21);
        uVar41 = *(undefined4 *)(puVar27 + select_sec + 0x1d);
        uVar40 = *(undefined4 *)(puVar27 + select_sec + 0x19);
        uVar38 = *(undefined4 *)(puVar27 + select_sec + 9);
        uVar36 = *(undefined4 *)(puVar27 + select_sec + 5);
        uVar34 = *(undefined4 *)(puVar27 + iVar25);
LAB_004599af:
        script_add_item(uVar34,uVar36,uVar38,uVar40,uVar41,uVar42,uVar43,uVar44,uVar47,uVar35,uVar37
                        ,uVar39,uVar45,uVar13,uVar12,uVar8,gm_mem_loc - param_2,uVar46,
                        param_9 & 0xffff);
        param_1 = param_1 + 0x40;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0x38:
        iVar21 = *(int *)(puVar27 + iVar25);
        iVar25 = select_sec + 5;
        select_sec = 0;
        if (0 < num_obj_handles) {
          puVar30 = &obj_handle;
          param_1 = iVar25;
          do {
            if (iVar21 == (&DAT_00617658)[select_sec]) {
              set_door_deltas(*puVar30,(&script_obj_handle)[select_sec],
                              *(undefined4 *)(puVar27 + iVar25),
                              *(undefined4 *)(puVar27 + iVar25 + 4),
                              *(undefined4 *)(puVar27 + iVar25 + 8),
                              *(undefined4 *)(puVar27 + iVar25 + 0xc),
                              *(undefined4 *)(puVar27 + iVar25 + 0x10),
                              *(undefined4 *)(puVar27 + iVar25 + 0x14),
                              *(undefined4 *)(puVar27 + iVar25 + 0x18),
                              *(undefined4 *)(puVar27 + iVar25 + 0x1c),
                              *(undefined4 *)(puVar27 + iVar25 + 0x20));
              iVar25 = param_1;
              puVar27 = selected_poly;
            }
            select_sec = select_sec + 1;
            puVar30 = puVar30 + 1;
          } while (select_sec < num_obj_handles);
        }
LAB_0045899a:
        select_sec = iVar25 + 0x24;
        param_1 = iVar25 + 0x24;
        break;
      case 0x39:
        iVar21 = *(int *)(puVar27 + iVar25);
        iVar25 = select_sec + 5;
        select_sec = 0;
        if (num_obj_handles < 1) goto LAB_0045c36a;
        puVar30 = &obj_handle;
        param_1 = iVar25;
        do {
          if (iVar21 == (&DAT_00617658)[select_sec]) {
            set_door_position(*puVar30,(&script_obj_handle)[select_sec],
                              *(undefined4 *)(puVar27 + iVar25));
            iVar25 = param_1;
            puVar27 = selected_poly;
          }
          select_sec = select_sec + 1;
          puVar30 = puVar30 + 1;
        } while (select_sec < num_obj_handles);
        select_sec = iVar25 + 4;
        param_1 = iVar25 + 4;
        break;
      case 0x3a:
        iVar21 = *(int *)(puVar27 + iVar25);
        iVar25 = select_sec + 5;
        select_sec = 0;
        if (num_obj_handles < 1) goto LAB_0045a18a;
        puVar30 = &obj_handle;
        param_1 = iVar25;
        do {
          if (iVar21 == (&DAT_00617658)[select_sec]) {
            set_door_sounds(*puVar30,(&script_obj_handle)[select_sec],
                            *(undefined4 *)(puVar27 + iVar25),*(undefined4 *)(puVar27 + iVar25 + 4),
                            *(undefined4 *)(puVar27 + iVar25 + 8),
                            *(undefined4 *)(puVar27 + iVar25 + 0xc),
                            *(undefined4 *)(puVar27 + iVar25 + 0x10),
                            *(undefined4 *)(puVar27 + iVar25 + 0x14),
                            *(undefined4 *)(puVar27 + iVar25 + 0x18),
                            *(undefined4 *)(puVar27 + iVar25 + 0x1c));
            iVar25 = param_1;
            puVar27 = selected_poly;
          }
          select_sec = select_sec + 1;
          puVar30 = puVar30 + 1;
        } while (select_sec < num_obj_handles);
        select_sec = iVar25 + 0x20;
        param_1 = iVar25 + 0x20;
        break;
      case 0x3b:
        iVar21 = *(int *)(puVar27 + iVar25);
        iVar25 = select_sec + 5;
        select_sec = 0;
        if (num_obj_handles < 1) goto LAB_0045c36a;
        puVar30 = &obj_handle;
        param_1 = iVar25;
        do {
          if (iVar21 == (&DAT_00617658)[select_sec]) {
            set_door_speed(*puVar30,(&script_obj_handle)[select_sec],
                           *(undefined4 *)(puVar27 + iVar25));
            iVar25 = param_1;
            puVar27 = selected_poly;
          }
          select_sec = select_sec + 1;
          puVar30 = puVar30 + 1;
        } while (select_sec < num_obj_handles);
        select_sec = iVar25 + 4;
        param_1 = iVar25 + 4;
        break;
      case 0x3c:
        _strncpy((char *)&game_name,puVar27 + iVar25,0x4f);
        DAT_005a47c7 = 0;
LAB_00457baf:
        script_handle_name(&param_1);
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0x3d:
        _strncpy((char *)&level_name,puVar27 + iVar25,0x4f);
        DAT_005a4817 = 0;
        goto LAB_0045b5e3;
      case 0x3e:
        _sprintf(&level_name,s_LEVEL%ld_004b8588,next_level_num);
        next_level_num = next_level_num + 1;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0x3f:
        end_game();
        menu_visible = 1;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0x40:
        items_move_check();
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0x41:
        uVar19 = (int)param_9 >> 0x10 & 0xffff;
        if ((uVar19 < 0x10c) || (0x237 < uVar19)) goto LAB_0045c36a;
        set_srcitem_trigger_event(uVar19 - 0x10c,*(undefined4 *)(puVar27 + iVar25));
        goto LAB_0045bfec;
      case 0x42:
        random();
        uVar8 = __ftol();
        random();
        uVar12 = __ftol();
        puVar30 = (undefined4 *)(selected_poly + param_1);
        random();
        uVar13 = __ftol();
        script_add_sprite(*puVar30,uVar8,uVar12,uVar13,puVar30[10],puVar30[0xb],puVar30[0xc],
                          puVar30[0xd],puVar30[0xe],puVar30[0xf],puVar30[0x10],0);
        param_1 = param_1 + 0x44;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0x43:
        iVar21 = *(int *)(puVar27 + select_sec + 0x11);
        iVar25 = random();
        iVar14 = param_1;
        puVar6 = selected_poly;
        iVar18 = *(int *)(puVar27 + select_sec + 5);
        select_sec = *(int *)(puVar27 + select_sec + 0x15);
        iVar10 = random();
        iVar23 = *(int *)(puVar6 + iVar14 + 8);
        iVar14 = *(int *)(puVar6 + iVar14 + 0x18);
        puVar30 = (undefined4 *)(selected_poly + param_1);
        iVar11 = random();
        script_add_sprite(*puVar30,((iVar25 % (iVar21 * 2 + 1) + iVar18) - iVar21) + param_6,
                          ((iVar10 % (select_sec * 2 + 1) + iVar23) - select_sec) + param_7,
                          ((iVar11 % (iVar14 * 2 + 1) + puVar30[3]) - iVar14) + param_8,puVar30[7],
                          puVar30[8],puVar30[9],puVar30[10],puVar30[0xb],puVar30[0xc],puVar30[0xd],0
                         );
        param_1 = param_1 + 0x38;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0x44:
        uVar19 = param_9 & 0xffff;
        param_1 = select_sec + 5;
        if (uVar19 < 8) {
          iVar21 = engine_getobjectptr((&selected_obj)[uVar19 * 0xd44]);
          select_sec = param_1;
          if (iVar21 == 0) {
            pcVar48 = s_Script_Run_Error:_Unable_to_get_o_004b82d0;
LAB_0045969e:
            log_message(pcVar48);
            param_1 = param_1 + 0x20;
            select_sec = param_1;
            puVar27 = selected_poly;
          }
          else {
            uVar8 = __ftol(*(undefined4 *)(selected_poly + param_1 + 4),
                           *(undefined4 *)(selected_poly + param_1 + 8),
                           *(undefined4 *)(selected_poly + param_1 + 0xc),
                           *(undefined4 *)(selected_poly + param_1 + 0x10),
                           *(undefined4 *)(selected_poly + param_1 + 0x14),
                           *(undefined4 *)(selected_poly + param_1 + 0x18),
                           *(undefined4 *)(selected_poly + param_1 + 0x1c),
                           (&selected_obj)[(param_9 & 0xffff) * 0xd44]);
            uVar8 = __ftol(uVar8);
            uVar8 = __ftol(uVar8);
            script_add_sprite(*(undefined4 *)(selected_poly + select_sec),uVar8);
            param_1 = param_1 + 0x20;
            select_sec = param_1;
            puVar27 = selected_poly;
          }
        }
        else {
          iVar21 = engine_getobjectptr((&thing_pointer)[(uVar19 - 8) * 0x14a]);
          select_sec = param_1;
          if (iVar21 == 0) {
            pcVar48 = s_Script_Run_Error:_Unable_to_get_o_004b8274;
            goto LAB_0045969e;
          }
          uVar8 = __ftol(*(undefined4 *)(selected_poly + param_1 + 4),
                         *(undefined4 *)(selected_poly + param_1 + 8),
                         *(undefined4 *)(selected_poly + param_1 + 0xc),
                         *(undefined4 *)(selected_poly + param_1 + 0x10),
                         *(undefined4 *)(selected_poly + param_1 + 0x14),
                         *(undefined4 *)(selected_poly + param_1 + 0x18),
                         *(undefined4 *)(selected_poly + param_1 + 0x1c),
                         (&thing_pointer)[((param_9 & 0xffff) - 8) * 0x14a]);
          uVar8 = __ftol(uVar8);
          uVar8 = __ftol(uVar8);
          script_add_sprite(*(undefined4 *)(selected_poly + select_sec),uVar8);
          param_1 = param_1 + 0x20;
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        break;
      case 0x45:
        add_sprite_moving(*(undefined4 *)(puVar27 + iVar25),
                          *(undefined4 *)(puVar27 + select_sec + 5),
                          *(undefined4 *)(puVar27 + select_sec + 9),
                          *(undefined4 *)(puVar27 + select_sec + 0xd),
                          *(undefined4 *)(puVar27 + select_sec + 0x11),
                          *(undefined4 *)(puVar27 + select_sec + 0x15),
                          *(undefined4 *)(puVar27 + select_sec + 0x19),
                          *(undefined4 *)(puVar27 + select_sec + 0x1d),
                          *(undefined4 *)(puVar27 + select_sec + 0x21),
                          *(undefined4 *)(puVar27 + select_sec + 0x25),
                          *(undefined4 *)(puVar27 + select_sec + 0x2d),
                          *(undefined4 *)(puVar27 + select_sec + 0x31),
                          *(undefined4 *)(puVar27 + select_sec + 0x35),
                          *(undefined4 *)(puVar27 + select_sec + 0x39),
                          *(undefined4 *)(puVar27 + select_sec + 0x3d),
                          *(undefined4 *)(puVar27 + select_sec + 0x41),
                          *(undefined4 *)(puVar27 + select_sec + 0x45),
                          *(undefined4 *)(puVar27 + select_sec + 0x29),0);
        param_1 = param_1 + 0x48;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0x46:
        iVar21 = *(int *)(puVar27 + select_sec + 0x11);
        iVar25 = random();
        iVar14 = param_1;
        puVar6 = selected_poly;
        iVar18 = *(int *)(puVar27 + select_sec + 5);
        select_sec = *(int *)(puVar27 + select_sec + 0x15);
        iVar10 = random();
        iVar23 = *(int *)(puVar6 + iVar14 + 8);
        iVar14 = *(int *)(puVar6 + iVar14 + 0x18);
        puVar30 = (undefined4 *)(selected_poly + param_1);
        iVar11 = random();
        add_sprite_moving(*puVar30,((iVar25 % (iVar21 * 2 + 1) + iVar18) - iVar21) + param_6,
                          ((iVar10 % (select_sec * 2 + 1) + iVar23) - select_sec) + param_7,
                          ((iVar11 % (iVar14 * 2 + 1) + puVar30[3]) - iVar14) + param_8,puVar30[7],
                          puVar30[8],puVar30[9],puVar30[10],puVar30[0xb],puVar30[0xc],puVar30[0xe],
                          puVar30[0xf],puVar30[0x10],puVar30[0x11],puVar30[0x12],puVar30[0x13],
                          puVar30[0x14],puVar30[0xd],0);
        param_1 = param_1 + 0x54;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0x47:
        random();
        random();
        random();
        uVar19 = param_9 & 0xffff;
        uVar8 = 0;
        if (uVar19 < 8) {
          if (((&tank_screen)[uVar19 * 0xd44] == 0) || ((&tank_screen)[uVar19 * 0xd44] == 7)) {
            select_sec = 0;
          }
          else {
            select_sec = engine_getobjectptr((&selected_obj)[uVar19 * 0xd44]);
            uVar19 = param_9 & 0xffff;
            uVar8 = (&selected_obj)[uVar19 * 0xd44];
          }
        }
        else {
          select_sec = engine_getobjectptr((&thing_pointer)[(uVar19 - 8) * 0x14a]);
          uVar19 = param_9 & 0xffff;
          uVar8 = (&thing_pointer)[(uVar19 - 8) * 0x14a];
        }
        iVar21 = param_1;
        puVar27 = selected_poly;
        if (select_sec == 0) {
          if (uVar19 < 8) {
            select_sec = uVar19 * 0x3510;
            if ((&tank_screen)[uVar19 * 0xd44] != 0) {
              matrix_relative_offset
                        (local_20,local_38,local_50,
                         *(undefined4 *)(&thing_offset_y + uVar19 * 0x6a2),
                         *(undefined4 *)((int)&thing_offset_y + select_sec + 4),
                         *(undefined4 *)(&thing_offset_x + uVar19 * 0x6a2),
                         *(undefined4 *)((int)&thing_offset_x + select_sec + 4),
                         *(undefined4 *)(&thing_offset_z + uVar19 * 0x6a2),
                         *(undefined4 *)((int)&thing_offset_z + select_sec + 4));
              select_sec = param_1;
              puVar27 = selected_poly;
              uVar8 = __ftol(*(undefined4 *)(selected_poly + param_1 + 0x1c),
                             *(undefined4 *)(selected_poly + param_1 + 0x20),
                             *(undefined4 *)(selected_poly + param_1 + 0x24),
                             *(undefined4 *)(selected_poly + param_1 + 0x28),
                             *(undefined4 *)(selected_poly + param_1 + 0x2c),
                             *(undefined4 *)(selected_poly + param_1 + 0x30),
                             *(undefined4 *)(selected_poly + param_1 + 0x38),
                             *(undefined4 *)(selected_poly + param_1 + 0x3c),
                             *(undefined4 *)(selected_poly + param_1 + 0x40),
                             *(undefined4 *)(selected_poly + param_1 + 0x44),
                             *(undefined4 *)(selected_poly + param_1 + 0x48),
                             *(undefined4 *)(selected_poly + param_1 + 0x4c),
                             *(undefined4 *)(selected_poly + param_1 + 0x50),
                             *(undefined4 *)(selected_poly + param_1 + 0x34),0);
              uVar8 = __ftol(uVar8);
              uVar8 = __ftol(uVar8);
              add_sprite_moving(*(undefined4 *)(puVar27 + select_sec),uVar8);
              goto LAB_00458fd1;
            }
            pcVar48 = s_ScriptRunError:_Unable_to_ADD_SP_004b8450;
          }
          else {
            pcVar48 = s_ScriptRunError:_Unable_to_get_th_004b83f8;
          }
          log_message(pcVar48);
        }
        else {
          uVar8 = __ftol(*(undefined4 *)(selected_poly + param_1 + 0x1c),
                         *(undefined4 *)(selected_poly + param_1 + 0x20),
                         *(undefined4 *)(selected_poly + param_1 + 0x24),
                         *(undefined4 *)(selected_poly + param_1 + 0x28),
                         *(undefined4 *)(selected_poly + param_1 + 0x2c),
                         *(undefined4 *)(selected_poly + param_1 + 0x30),
                         *(undefined4 *)(selected_poly + param_1 + 0x38),
                         *(undefined4 *)(selected_poly + param_1 + 0x3c),
                         *(undefined4 *)(selected_poly + param_1 + 0x40),
                         *(undefined4 *)(selected_poly + param_1 + 0x44),
                         *(undefined4 *)(selected_poly + param_1 + 0x48),
                         *(undefined4 *)(selected_poly + param_1 + 0x4c),
                         *(undefined4 *)(selected_poly + param_1 + 0x50),
                         *(undefined4 *)(selected_poly + param_1 + 0x34),uVar8);
          uVar8 = __ftol(uVar8);
          uVar8 = __ftol(uVar8);
          add_sprite_moving(*(undefined4 *)(puVar27 + iVar21),uVar8);
        }
LAB_00458fd1:
        select_sec = param_1 + 0x54;
        puVar27 = selected_poly;
        param_1 = param_1 + 0x54;
        break;
      case 0x48:
        uVar19 = param_9 & 0xffff;
        param_1 = select_sec + 5;
        if (uVar19 < 8) {
          iVar21 = engine_getobjectptr((&selected_obj)[uVar19 * 0xd44]);
          select_sec = param_1;
          puVar27 = selected_poly;
          if (iVar21 == 0) {
            pcVar48 = s_Script_Run_Error:_Unable_to_get_o_004b8394;
LAB_004592ac:
            log_message(pcVar48);
            param_1 = param_1 + 0x3c;
            select_sec = param_1;
            puVar27 = selected_poly;
          }
          else {
            uVar8 = __ftol(*(undefined4 *)(selected_poly + param_1 + 4),
                           *(undefined4 *)(selected_poly + param_1 + 8),
                           *(undefined4 *)(selected_poly + param_1 + 0xc),
                           *(undefined4 *)(selected_poly + param_1 + 0x10),
                           *(undefined4 *)(selected_poly + param_1 + 0x14),
                           *(undefined4 *)(selected_poly + param_1 + 0x18),
                           *(undefined4 *)(selected_poly + param_1 + 0x20),
                           *(undefined4 *)(selected_poly + param_1 + 0x24),
                           *(undefined4 *)(selected_poly + param_1 + 0x28),
                           *(undefined4 *)(selected_poly + param_1 + 0x2c),
                           *(undefined4 *)(selected_poly + param_1 + 0x30),
                           *(undefined4 *)(selected_poly + param_1 + 0x34),
                           *(undefined4 *)(selected_poly + param_1 + 0x38),
                           *(undefined4 *)(selected_poly + param_1 + 0x1c),
                           (&selected_obj)[(param_9 & 0xffff) * 0xd44]);
            uVar8 = __ftol(uVar8);
            uVar8 = __ftol(uVar8);
            add_sprite_moving(*(undefined4 *)(puVar27 + select_sec),uVar8);
            param_1 = param_1 + 0x3c;
            select_sec = param_1;
            puVar27 = selected_poly;
          }
        }
        else {
          iVar21 = engine_getobjectptr((&thing_pointer)[(uVar19 - 8) * 0x14a]);
          select_sec = param_1;
          puVar27 = selected_poly;
          if (iVar21 == 0) {
            pcVar48 = s_Script_Run_Error:_Unable_to_get_o_004b8330;
            goto LAB_004592ac;
          }
          uVar8 = __ftol(*(undefined4 *)(selected_poly + param_1 + 4),
                         *(undefined4 *)(selected_poly + param_1 + 8),
                         *(undefined4 *)(selected_poly + param_1 + 0xc),
                         *(undefined4 *)(selected_poly + param_1 + 0x10),
                         *(undefined4 *)(selected_poly + param_1 + 0x14),
                         *(undefined4 *)(selected_poly + param_1 + 0x18),
                         *(undefined4 *)(selected_poly + param_1 + 0x20),
                         *(undefined4 *)(selected_poly + param_1 + 0x24),
                         *(undefined4 *)(selected_poly + param_1 + 0x28),
                         *(undefined4 *)(selected_poly + param_1 + 0x2c),
                         *(undefined4 *)(selected_poly + param_1 + 0x30),
                         *(undefined4 *)(selected_poly + param_1 + 0x34),
                         *(undefined4 *)(selected_poly + param_1 + 0x38),
                         *(undefined4 *)(selected_poly + param_1 + 0x1c),
                         (&thing_pointer)[((param_9 & 0xffff) - 8) * 0x14a]);
          uVar8 = __ftol(uVar8);
          uVar8 = __ftol(uVar8);
          add_sprite_moving(*(undefined4 *)(puVar27 + select_sec),uVar8);
          param_1 = param_1 + 0x3c;
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        break;
      case 0x49:
        iVar21 = *(int *)(puVar27 + select_sec + 0x15);
        iVar14 = random();
        iVar23 = param_1;
        puVar6 = selected_poly;
        iVar18 = *(int *)(puVar27 + select_sec + 0x19);
        iVar21 = (iVar14 % (iVar21 * 2 + 1) + *(int *)(puVar27 + select_sec + 9)) - iVar21;
        iVar14 = random();
        select_sec = *(int *)(puVar6 + iVar23 + 0x1c);
        iVar18 = (iVar14 % (iVar18 * 2 + 1) + *(int *)(puVar6 + iVar23 + 0xc)) - iVar18;
        puVar30 = (undefined4 *)(selected_poly + param_1);
        iVar23 = random();
        select_sec = (iVar23 % (select_sec * 2 + 1) + puVar30[4]) - select_sec;
        uVar19 = param_9 & 0xffff;
        if ((param_9 & 0xffff) < 8) {
          if (-1 < (int)puVar30[0xe]) {
            iVar21 = __ftol();
            iVar18 = __ftol();
            select_sec = __ftol();
          }
          srcplayer_get_attached_sprite
                    (uVar19,*puVar30,puVar30[1],iVar21,iVar18,select_sec,puVar30[8],puVar30[9],
                     puVar30[10],puVar30[0xb],puVar30[0xc],puVar30[0xd],puVar30[0xf]);
          param_1 = param_1 + 0x40;
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        else {
          if (0x10b < (param_9 & 0xffff)) goto LAB_0045b6b9;
          if (-1 < (int)puVar30[0xe]) {
            iVar21 = __ftol();
            iVar18 = __ftol();
            select_sec = __ftol();
          }
          srcthing_get_attached_sprite
                    (uVar19 - 8,*puVar30,puVar30[1],iVar21,iVar18,select_sec,puVar30[8],puVar30[9],
                     puVar30[10],puVar30[0xb],puVar30[0xc],puVar30[0xd],puVar30[0xf]);
          param_1 = param_1 + 0x40;
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        break;
      case 0x4a:
        uVar19 = param_9 & 0xffff;
        if (uVar19 < 8) {
          remove_srcplayer_sprite(uVar19,*(undefined4 *)(puVar27 + iVar25));
        }
        else {
          if (0x10b < uVar19) goto LAB_0045c36a;
          remove_srcthing_sprite(uVar19 - 8,*(undefined4 *)(puVar27 + iVar25));
        }
        goto LAB_0045bfec;
      case 0x4b:
        damage_blast_radius(param_9 & 0xffff,*(undefined4 *)(puVar27 + iVar25),
                            *(undefined4 *)(puVar27 + select_sec + 5),param_6,param_7,param_8,
                            *(undefined4 *)(puVar27 + select_sec + 9),
                            *(undefined4 *)(puVar27 + select_sec + 0xd),
                            *(undefined4 *)(puVar27 + select_sec + 0x11),
                            *(undefined4 *)(puVar27 + select_sec + 0x15));
        if (0 < *(int *)(selected_poly + param_1 + 8)) {
          blast_radius_fallback
                    (param_6,param_7,iVar14,*(undefined4 *)(selected_poly + param_1 + 0x10),
                     param_9 & 0xffff);
          calc_distance_from_blast_radius
                    (param_9 & 0xffff,(double)param_6,(double)param_7,(double)param_8,
                     (double)*(int *)(selected_poly + param_1 + 0x10));
        }
        select_sec = param_1 + 0x18;
        puVar27 = selected_poly;
        param_1 = param_1 + 0x18;
        break;
      case 0x4c:
        param_9 = (param_9 & 0xffff0000) + 0xffff;
        select_sec = iVar25;
        break;
      case 0x4d:
        camera_pitch_shake_period = *(int *)(puVar27 + select_sec + 9);
        camera_pitch_shake_dur = *(undefined4 *)(puVar27 + select_sec + 0xd);
        select_sec = select_sec + 0x11;
        if (camera_pitch_shake_period < 1) {
          camera_pitch_shake_period = 1;
        }
        _DAT_0080f828 = *(double *)(puVar27 + iVar25) / (double)camera_pitch_shake_period;
        param_1 = select_sec;
        break;
      case 0x4e:
        camera_roll_shake_period = *(int *)(puVar27 + select_sec + 9);
        camera_roll_shake_dur = *(undefined4 *)(puVar27 + select_sec + 0xd);
        select_sec = select_sec + 0x11;
        if (camera_roll_shake_period < 1) {
          camera_roll_shake_period = 1;
        }
        _DAT_0080f820 = *(double *)(puVar27 + iVar25) / (double)camera_roll_shake_period;
        param_1 = select_sec;
        break;
      case 0x4f:
        camera_yaw_shake_period = *(int *)(puVar27 + select_sec + 9);
        camera_yaw_shake_dur = *(undefined4 *)(puVar27 + select_sec + 0xd);
        select_sec = select_sec + 0x11;
        if (camera_yaw_shake_period < 1) {
          camera_yaw_shake_period = 1;
        }
        _DAT_0080f838 = *(double *)(puVar27 + iVar25) / (double)camera_yaw_shake_period;
        param_1 = select_sec;
        break;
      case 0x50:
        _camera_haze = *(undefined8 *)(puVar27 + iVar25);
        if (0.0 < *(double *)(puVar27 + select_sec + 9)) {
          _camera_haze_decay = *(double *)(puVar27 + select_sec + 9) * 0.91;
          goto LAB_0045b406;
        }
        select_sec = select_sec + 0x11;
        _camera_haze_decay = 0.0;
        param_1 = select_sec;
        break;
      case 0x51:
        if ((setting_on != 0) &&
           (select_sec = script_load_music(*(undefined4 *)(puVar27 + iVar25),
                                           puVar27 + select_sec + 5,1), select_sec != 0)) {
          log_message(s_Script_run_error:_unable_to_load_004b8200,selected_poly + param_1 + 4);
        }
        param_1 = param_1 + 4;
LAB_0045b5e3:
        script_handle_name(&param_1);
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0x52:
        if (setting_on == 0) goto LAB_0045c36a;
        play_music(*(undefined4 *)(puVar27 + iVar25));
        sound_handle_count = *(int *)(selected_poly + param_1);
        select_sec = param_1 + 4;
        puVar27 = selected_poly;
        param_1 = param_1 + 4;
        break;
      case 0x53:
        select_sec = iVar25;
        if (setting_on != 0) {
          stop_music();
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        break;
      case 0x54:
        if (setting_on == 0) goto LAB_0045c36a;
        unload_music(*(undefined4 *)(puVar27 + iVar25));
        goto LAB_0045bfec;
      case 0x55:
        mem_music_bank = sound_handle_count;
        select_sec = iVar25;
        break;
      case 0x56:
        select_sec = iVar25;
        if ((setting_on != 0) && (-1 < mem_music_bank)) {
          play_music(mem_music_bank);
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        break;
      case 0x57:
        add_light_source(*(undefined4 *)(puVar27 + iVar25),*(undefined4 *)(puVar27 + select_sec + 5)
                         ,*(undefined4 *)(puVar27 + select_sec + 9),
                         *(undefined4 *)(puVar27 + select_sec + 0xd),
                         *(undefined4 *)(puVar27 + select_sec + 0x11),
                         *(undefined4 *)(puVar27 + select_sec + 0x15),
                         *(undefined4 *)(puVar27 + select_sec + 0x19),
                         *(undefined4 *)(puVar27 + select_sec + 0x1d),
                         *(undefined4 *)(puVar27 + select_sec + 0x21),
                         *(undefined4 *)(puVar27 + select_sec + 0x25),
                         *(undefined4 *)(puVar27 + select_sec + 0x29),
                         *(undefined4 *)(puVar27 + select_sec + 0x2d),
                         *(undefined4 *)(puVar27 + select_sec + 0x31),
                         *(undefined4 *)(puVar27 + select_sec + 0x35),
                         *(undefined4 *)(puVar27 + select_sec + 0x39),
                         *(undefined4 *)(puVar27 + select_sec + 0x3d));
LAB_0045b6b9:
        param_1 = param_1 + 0x40;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0x58:
        add_sky_light_source
                  (*(undefined4 *)(puVar27 + iVar25),*(undefined4 *)(puVar27 + select_sec + 5),
                   *(undefined4 *)(puVar27 + select_sec + 9),
                   *(undefined4 *)(puVar27 + select_sec + 0xd),
                   *(undefined4 *)(puVar27 + select_sec + 0x11),
                   *(undefined4 *)(puVar27 + select_sec + 0x15),
                   *(undefined4 *)(puVar27 + select_sec + 0x19));
        param_1 = param_1 + 0x1c;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0x59:
        piVar16 = (int *)(puVar27 + iVar25);
        iVar25 = select_sec + 5;
        select_sec = 0;
        if (0 < num_poly_handles) {
          piVar24 = &select_poly_handle;
          do {
            if (*piVar16 == *piVar24) break;
            select_sec = select_sec + 1;
            piVar24 = piVar24 + 1;
          } while (select_sec < num_poly_handles);
        }
        param_1 = iVar25;
        if (select_sec < num_poly_handles) {
          select_sec = 0;
          if (0 < num_poly_handles) {
            piVar16 = &select_poly_handle;
            do {
              if (*(int *)(puVar27 + iVar25) == *piVar16) break;
              select_sec = select_sec + 1;
              piVar16 = piVar16 + 1;
            } while (select_sec < num_poly_handles);
          }
          if (select_sec < num_poly_handles) goto LAB_0045c36a;
          log_message(s_Script_run_error:_unable_to_find_004b84fc);
        }
        else {
          log_message(s_Script_run_error:_unable_to_find_004b84ac);
        }
        goto LAB_0045bfec;
      case 0x5a:
        uVar19 = 0xffffffff;
        pcVar48 = selected_poly + iVar25;
        do {
          pcVar28 = pcVar48;
          if (uVar19 == 0) break;
          uVar19 = uVar19 - 1;
          pcVar28 = pcVar48 + 1;
          cVar7 = *pcVar48;
          pcVar48 = pcVar28;
        } while (cVar7 != '\0');
        uVar19 = ~uVar19;
        puVar30 = (undefined4 *)(pcVar28 + -uVar19);
        puVar29 = &stored_level_name;
        for (uVar15 = uVar19 >> 2; uVar15 != 0; uVar15 = uVar15 - 1) {
          *puVar29 = *puVar30;
          puVar30 = puVar30 + 1;
          puVar29 = puVar29 + 1;
        }
        for (uVar19 = uVar19 & 3; uVar19 != 0; uVar19 = uVar19 - 1) {
          *(undefined *)puVar29 = *(undefined *)puVar30;
          puVar30 = (undefined4 *)((int)puVar30 + 1);
          puVar29 = (undefined4 *)((int)puVar29 + 1);
        }
        goto LAB_0045c028;
      case 0x5b:
        side_screen = 5;
        DAT_0083d638 = gm_mem_loc / 0x5b;
        DAT_0083d2c0 = get_high_score(&stored_level_name,DAT_0083d638);
        cVar7 = script_exit();
        while (select_sec = param_1, puVar27 = selected_poly, cVar7 != '\0') {
          cVar7 = script_exit();
        }
        break;
      case 0x5c:
        _end_camera_x = *(undefined4 *)(puVar27 + iVar25);
        param_1 = select_sec + 0xd;
        _end_camera_y = *(undefined4 *)(puVar27 + select_sec + 5);
        _end_camera_z = *(undefined4 *)(puVar27 + select_sec + 9);
        select_sec = param_1;
        break;
      case 0x5d:
        level_best_time = *(undefined4 *)(puVar27 + iVar25);
        select_sec = select_sec + 5;
        param_1 = select_sec;
        break;
      case 0x5e:
        level_secrets = *(undefined4 *)(puVar27 + iVar25);
        select_sec = select_sec + 5;
        param_1 = select_sec;
        break;
      case 0x5f:
        select_sec = iVar25;
        if ((param_9 & 0xffff) < 8) {
          increment_source_player_secret_tally(param_9 & 0xffff);
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        break;
      case 0x60:
        _level_gravity = *(undefined8 *)(puVar27 + iVar25);
        select_sec = select_sec + 9;
        param_1 = select_sec;
        break;
      case 0x61:
        level_fog_r = *(undefined4 *)(puVar27 + iVar25);
        param_1 = select_sec + 0xd;
        level_fog_g = *(undefined4 *)(puVar27 + select_sec + 5);
        level_fog_b = *(undefined4 *)(puVar27 + select_sec + 9);
        select_sec = param_1;
        break;
      case 0x62:
        level_fog_distance = *(undefined4 *)(puVar27 + iVar25);
        select_sec = select_sec + 5;
        param_1 = select_sec;
        break;
      case 99:
        level_countdown = *(undefined4 *)(puVar27 + iVar25);
        select_sec = select_sec + 5;
        param_1 = select_sec;
        break;
      case 100:
        _level_focal_adjust = *(undefined8 *)(puVar27 + iVar25);
        select_sec = select_sec + 9;
        param_1 = select_sec;
        break;
      case 0x65:
        _max_anti_value = *(undefined8 *)(puVar27 + iVar25);
        _anti_angle_ratio = *(undefined8 *)(puVar27 + select_sec + 9);
        select_sec = select_sec + 0x11;
        param_1 = select_sec;
        break;
      case 0x66:
        level_version = *(undefined2 *)(puVar27 + iVar25);
        select_sec = select_sec + 5;
        param_1 = select_sec;
        break;
      case 0x67:
        iVar21 = *(int *)(puVar27 + iVar25);
        param_1 = select_sec + 5;
        if (0x1e < iVar21) {
          log_message(s_Script_run_error:_Maximum_level_o_004b80f0,0x1e,iVar21);
          return;
        }
        iVar18 = 0;
        select_sec = param_1;
        level_obj_complete = iVar21;
        if (0 < iVar21) {
          puVar30 = &DAT_0080d800;
          do {
            *puVar30 = selected_poly + param_1;
            script_handle_name(&param_1);
            iVar18 = iVar18 + 1;
            puVar30 = puVar30 + 1;
            select_sec = param_1;
            puVar27 = selected_poly;
          } while (iVar18 < level_obj_complete);
        }
        break;
      case 0x68:
        level_objective_bits = level_objective_bits | *(uint *)(puVar27 + iVar25);
        select_sec = select_sec + 5;
        param_1 = select_sec;
        break;
      case 0x69:
        uVar19 = param_9 & 0xffff;
        if (7 < uVar19) goto LAB_0045c36a;
        select_sec = select_sec + 5;
        (&key_bits)[uVar19 * 0xd44] = (&key_bits)[uVar19 * 0xd44] & *(uint *)(puVar27 + iVar25);
        param_1 = select_sec;
        break;
      case 0x6a:
        uVar19 = param_9 & 0xffff;
        if (7 < uVar19) goto LAB_0045c36a;
        select_sec = select_sec + 5;
        (&key_bits)[uVar19 * 0xd44] = (&key_bits)[uVar19 * 0xd44] | *(uint *)(puVar27 + iVar25);
        param_1 = select_sec;
        break;
      case 0x6b:
        if (7 < (param_9 & 0xffff)) goto LAB_0045c36a;
        puVar22 = &weapon_bits + (param_9 & 0xffff) * 0xd44;
LAB_0045bbc0:
        *puVar22 = *puVar22 & *(uint *)(puVar27 + iVar25);
        srcplayer_update_weapon_bits(param_9 & 0xffff);
        goto LAB_0045bfec;
      case 0x6c:
        if (7 < (param_9 & 0xffff)) goto LAB_0045c36a;
        puVar22 = &weapon_bits + (param_9 & 0xffff) * 0xd44;
LAB_0045bc03:
        *puVar22 = *puVar22 | *(uint *)(puVar27 + iVar25);
        srcplayer_update_weapon_bits(param_9 & 0xffff);
        goto LAB_0045bfec;
      case 0x6d:
        uVar19 = param_9 & 0xffff;
        if (7 < uVar19) goto LAB_0045c3f6;
        iVar18 = *(int *)(puVar27 + iVar25);
        iVar21 = iVar18 + uVar19 * 0xd44;
        iVar23 = (&ammo_available)[iVar21];
        select_sec = iVar23 + *(int *)(puVar27 + select_sec + 5);
        (&ammo_available)[iVar21] = select_sec;
        if (select_sec < 0) {
          (&ammo_available)[iVar21] = 0;
        }
        if ((int)(&ammo_max_rounds)[iVar18 * 0xe] < (int)(&ammo_available)[iVar21]) {
          (&ammo_available)[iVar21] = (&ammo_max_rounds)[iVar18 * 0xe];
        }
        srcplayer_update_weapon_bits(uVar19);
        if (((iVar23 < 1) &&
            (uVar19 = param_9 & 0xffff, 0 < (int)(&ammo_available)[uVar19 * 0xd44 + iVar18])) &&
           (((&srcplayer_flags)[uVar19 * 0xd44] & 0x8000) != 0)) {
          srcplayer_add_ammo(uVar19,iVar18,0);
        }
        select_sec = param_1 + 8;
        puVar27 = selected_poly;
        param_1 = param_1 + 8;
        break;
      case 0x6e:
        if ((param_9 & 0xffff) < 8) {
          puVar22 = &srcplayer_equipment_bits + (param_9 & 0xffff) * 0xd44;
          goto LAB_0045bbc0;
        }
        goto LAB_0045c36a;
      case 0x6f:
        if ((param_9 & 0xffff) < 8) {
          puVar22 = &srcplayer_equipment_bits + (param_9 & 0xffff) * 0xd44;
          goto LAB_0045bc03;
        }
        goto LAB_0045c36a;
      case 0x70:
        iVar21 = *(int *)(puVar27 + select_sec + 5);
        param_1 = select_sec + 9;
        if ((*(uint *)(puVar27 + iVar25) & 1) != 0) {
          iVar21 = iVar21 * DAT_005e4270;
        }
        uVar15 = param_9 & 0xffff;
        uVar19 = param_9 & 0xffff;
        select_sec = param_1;
        if (uVar15 < 8) {
          iVar23 = uVar15 * 0x3510;
          iVar18 = (&src_player_life_max)[uVar15 * 0xd44];
          if (iVar21 < 1) {
            if (iVar21 < 0) {
              heal_srcplayer(uVar19,0,(double)param_6,(double)param_7,(double)param_8,0,-iVar21,
                             uVar19);
              select_sec = param_1;
              puVar27 = selected_poly;
            }
          }
          else {
            iVar21 = iVar21 + iVar18;
            (&src_player_life_max)[uVar15 * 0xd44] = iVar21;
            if ((int)(&src_player_life_cur)[uVar15 * 0xd44] < iVar21) {
              (&src_player_life_max)[uVar15 * 0xd44] = (&src_player_life_cur)[uVar15 * 0xd44];
            }
            if ((iVar18 < (int)(&src_player_life_cur)[uVar15 * 0xd44] / 2) &&
               ((int)(&src_player_life_cur)[uVar15 * 0xd44] / 2 <=
                (int)(&src_player_life_max)[uVar15 * 0xd44])) {
              generate_for_thing(0xffffffee,(&srcplayer_sector_flags)[uVar15 * 0xd44],0,0,
                                 *(undefined4 *)(&sector_px + uVar15 * 0x6a2),
                                 *(undefined4 *)((int)&sector_px + iVar23 + 4),
                                 *(undefined4 *)(&sector_py + uVar15 * 0x6a2),
                                 *(undefined4 *)((int)&sector_py + iVar23 + 4),
                                 *(undefined4 *)(&sector_pz + uVar15 * 0x6a2),
                                 *(undefined4 *)((int)&sector_pz + iVar23 + 4),uVar19 - 0x10000);
              select_sec = param_1;
              puVar27 = selected_poly;
            }
          }
        }
        else if (uVar15 < 0x10c) {
          if (iVar21 < 1) {
            calc_target_damage(uVar19 - 8,0,(double)param_6,(double)param_7,(double)param_8,0,
                               -iVar21,uVar19);
            select_sec = param_1;
            puVar27 = selected_poly;
          }
          else {
            thing_heal(uVar19 - 8,0,iVar21);
            select_sec = param_1;
            puVar27 = selected_poly;
          }
        }
        break;
      case 0x71:
        iVar21 = *(int *)(puVar27 + select_sec + 5);
        param_1 = select_sec + 9;
        if ((*(uint *)(puVar27 + iVar25) & 1) != 0) {
          iVar21 = iVar21 * DAT_005e4270;
        }
        uVar19 = param_9 & 0xffff;
        select_sec = param_1;
        if (uVar19 < 8) {
          if (iVar21 < 1) {
            if (iVar21 < 0) {
              heal_srcplayer(uVar19,0,(double)param_6,(double)param_7,(double)param_8,-iVar21,0,
                             uVar19);
              select_sec = param_1;
              puVar27 = selected_poly;
            }
          }
          else {
            if ((*(uint *)(puVar27 + iVar25) & 2) == 0) {
              select_sec = 4;
              piVar16 = &front_shield_cur + uVar19 * 0xd44;
              do {
                iVar18 = *piVar16;
                *piVar16 = iVar18 + iVar21;
                if (piVar16[4] < iVar18 + iVar21) {
                  *piVar16 = piVar16[4];
                }
                piVar16 = piVar16 + 1;
                select_sec = select_sec + -1;
              } while (select_sec != 0);
            }
            else {
              select_sec = 0;
              iVar18 = 0;
              do {
                if (iVar21 < 1) break;
                if (3 < iVar18) {
                  iVar18 = 0;
                  select_sec = 0;
                }
                iVar23 = iVar18 + uVar19 * 0xd44;
                if ((int)(&front_shield_cur)[iVar23] < (int)(&DAT_0081c2a0)[iVar23]) {
                  iVar21 = iVar21 + -1;
                  (&front_shield_cur)[iVar23] = (&front_shield_cur)[iVar23] + 1;
                }
                else {
                  select_sec = select_sec + 1;
                }
                iVar18 = iVar18 + 1;
              } while (select_sec < 4);
            }
            if (((&srcplayer_flags)[uVar19 * 0xd44] & 0x40) == 0) {
              (&srcplayer_flags)[uVar19 * 0xd44] = (&srcplayer_flags)[uVar19 * 0xd44] & 0xffffff7f;
            }
            tweak_srcplayer_status(uVar19);
            select_sec = param_1;
            puVar27 = selected_poly;
          }
        }
        else if (uVar19 < 0x10c) {
          if (iVar21 < 1) {
            calc_target_damage(uVar19 - 8,0,(double)param_6,(double)param_7,(double)param_8,-iVar21,
                               0,uVar19);
            select_sec = param_1;
            puVar27 = selected_poly;
          }
          else {
            thing_heal(uVar19 - 8,iVar21,0);
            select_sec = param_1;
            puVar27 = selected_poly;
          }
        }
        break;
      case 0x72:
        uVar19 = param_9 & 0xffff;
        if (uVar19 < 8) {
          iVar21 = *(int *)(puVar27 + iVar25);
          iVar18 = (&curr_cash)[uVar19 * 0xd44];
          (&curr_cash)[uVar19 * 0xd44] = iVar18 + iVar21;
          if (iVar18 + iVar21 < 0) {
            select_sec = select_sec + 5;
            (&curr_cash)[uVar19 * 0xd44] = 0;
            param_1 = select_sec;
            break;
          }
        }
        goto LAB_0045c36a;
      case 0x73:
        uVar19 = param_9 & 0xffff;
        if (7 < uVar19) goto LAB_0045c36a;
        select_sec = select_sec + 5;
        (&curr_salvage)[uVar19 * 0xd44] =
             (&curr_salvage)[uVar19 * 0xd44] + *(int *)(puVar27 + iVar25);
        param_1 = select_sec;
        break;
      case 0x74:
        uVar19 = param_9 & 0xffff;
        if ((uVar19 < 8) || (0x10b < uVar19)) goto LAB_0045c36a;
        select_sec = thing_change_sob(uVar19 - 8,*(undefined4 *)(puVar27 + iVar25),
                                      gm_mem_loc - param_2);
        if (select_sec != 0) {
          log_message(s_Warning:_Bad_return_value_for_sc_004b822c);
        }
        goto LAB_0045bfec;
      case 0x75:
        uVar19 = param_9 & 0xffff;
        if ((7 < uVar19) ||
           (iVar21 = *(int *)(puVar27 + iVar25),
           iVar18 = *(int *)(&srcplayer_speed + uVar19 * 0x3510),
           *(int *)(&srcplayer_speed + uVar19 * 0x3510) = iVar18 + iVar21, iVar18 + iVar21 < 1))
        goto LAB_0045c36a;
        select_sec = select_sec + 5;
        (&srcplayer_flags)[uVar19 * 0xd44] = (&srcplayer_flags)[uVar19 * 0xd44] | 2;
        param_1 = select_sec;
        break;
      case 0x76:
        uVar19 = param_9 & 0xffff;
        if (7 < uVar19) goto LAB_0045c3f6;
        iVar21 = uVar19 * 0x3510;
        param_1 = select_sec + 9;
        fVar32 = (float10)fcos((float10)*(double *)(&player_recoilflag1 + iVar21));
        fVar33 = (float10)fsin((float10)(double)(&thing_offset_z)[uVar19 * 0x6a2]);
        *(double *)(&DAT_0081bd90 + iVar21) =
             (double)((float10)*(double *)(&DAT_0081bd90 + iVar21) -
                     fVar33 * ABS(fVar32) * (float10)*(double *)(puVar27 + select_sec + 1));
        fVar32 = (float10)fcos((float10)*(double *)(&player_recoilflag1 + iVar21));
        fVar33 = (float10)fcos((float10)(double)(&thing_offset_z)[uVar19 * 0x6a2]);
        *(double *)(&DAT_0081bd98 + iVar21) =
             (double)((float10)*(double *)(&DAT_0081bd98 + iVar21) -
                     fVar33 * ABS(fVar32) * (float10)*(double *)(puVar27 + select_sec + 1));
        select_sec = param_1;
        break;
      case 0x77:
        uVar19 = param_9 & 0xffff;
        if (uVar19 < 8) {
          iVar21 = uVar19 * 0x3510;
          (&player_col_x_radius)[uVar19 * 0x6a2] = (double)*(int *)(puVar27 + select_sec + 5);
          (&player_col_y_radius)[uVar19 * 0x6a2] = (double)*(int *)(puVar27 + select_sec + 9);
          (&player_col_z_radius)[uVar19 * 0x6a2] = (double)*(int *)(puVar27 + select_sec + 0xd);
          (&DAT_0081bda8)[uVar19 * 0x6a2] = (&player_col_x_radius)[uVar19 * 0x6a2];
          if ((&player_col_x_radius)[uVar19 * 0x6a2] < (&player_col_y_radius)[uVar19 * 0x6a2]) {
            *(undefined4 *)(&DAT_0081bda8 + uVar19 * 0x6a2) =
                 *(undefined4 *)(&player_col_y_radius + uVar19 * 0x6a2);
            *(undefined4 *)((int)&DAT_0081bda8 + iVar21 + 4) =
                 *(undefined4 *)((int)&player_col_y_radius + iVar21 + 4);
          }
          if ((double)(&DAT_0081bda8)[uVar19 * 0x6a2] <
              (double)(&player_col_z_radius)[uVar19 * 0x6a2]) {
            *(undefined4 *)(&DAT_0081bda8 + uVar19 * 0x6a2) =
                 *(undefined4 *)(&player_col_z_radius + uVar19 * 0x6a2);
            *(undefined4 *)((int)&DAT_0081bda8 + iVar21 + 4) =
                 *(undefined4 *)((int)&player_col_z_radius + iVar21 + 4);
          }
          if (*(int *)(puVar27 + iVar25) == 1) {
            select_sec = select_sec + 0x11;
            *(undefined4 *)(&player_col_x_radius + uVar19 * 0x6a2) =
                 *(undefined4 *)(&DAT_0081bda8 + uVar19 * 0x6a2);
            *(undefined4 *)((int)&player_col_x_radius + iVar21 + 4) =
                 *(undefined4 *)((int)&DAT_0081bda8 + iVar21 + 4);
            *(undefined4 *)(&player_col_y_radius + uVar19 * 0x6a2) =
                 *(undefined4 *)(&DAT_0081bda8 + uVar19 * 0x6a2);
            *(undefined4 *)((int)&player_col_y_radius + iVar21 + 4) =
                 *(undefined4 *)((int)&DAT_0081bda8 + iVar21 + 4);
            *(undefined4 *)(&player_col_z_radius + uVar19 * 0x6a2) =
                 *(undefined4 *)(&DAT_0081bda8 + uVar19 * 0x6a2);
            *(undefined4 *)((int)&player_col_z_radius + iVar21 + 4) =
                 *(undefined4 *)((int)&DAT_0081bda8 + iVar21 + 4);
            param_1 = select_sec;
          }
          else {
            if (*(int *)(puVar27 + iVar25) == 2) goto LAB_0045b406;
            *(undefined4 *)(&DAT_0081bda8 + uVar19 * 0x6a2) = 0;
            *(undefined4 *)((int)&DAT_0081bda8 + iVar21 + 4) = 0x3ff00000;
            *(undefined4 *)(&player_col_x_radius + uVar19 * 0x6a2) = 0;
            *(undefined4 *)((int)&player_col_x_radius + iVar21 + 4) = 0x3ff00000;
            *(undefined4 *)(&player_col_y_radius + uVar19 * 0x6a2) = 0;
            *(undefined4 *)((int)&player_col_y_radius + iVar21 + 4) = 0x3ff00000;
            select_sec = select_sec + 0x11;
            *(undefined4 *)(&player_col_z_radius + uVar19 * 0x6a2) = 0;
            *(undefined4 *)((int)&player_col_z_radius + iVar21 + 4) = 0x3ff00000;
            param_1 = select_sec;
          }
        }
        else {
          if (0x10b < uVar19) goto LAB_0045b406;
          iVar21 = uVar19 - 8;
          iVar18 = iVar21 * 0x528;
          *(undefined4 *)(&DAT_007ac3b0 + iVar18) = *(undefined4 *)(puVar27 + iVar25);
          *(double *)(&thing_col_x_radius + iVar21 * 0x14a) =
               (double)*(int *)(puVar27 + select_sec + 5);
          *(double *)(&thing_col_y_radius + iVar21 * 0x14a) =
               (double)*(int *)(puVar27 + select_sec + 9);
          *(double *)(&thing_col_z_radius + iVar21 * 0x14a) =
               (double)*(int *)(puVar27 + select_sec + 0xd);
          dVar1 = *(double *)(&thing_col_x_radius + iVar21 * 0x14a);
          (&thing_general_col_radius)[iVar21 * 0xa5] = dVar1;
          if (dVar1 < *(double *)(&thing_col_y_radius + iVar21 * 0x14a)) {
            *(undefined4 *)(&thing_general_col_radius + iVar21 * 0xa5) =
                 (&thing_col_y_radius)[iVar21 * 0x14a];
            *(undefined4 *)((int)&thing_general_col_radius + iVar18 + 4) =
                 (&DAT_007ac10c)[iVar21 * 0x14a];
          }
          if ((double)(&thing_general_col_radius)[iVar21 * 0xa5] <
              *(double *)(&thing_col_z_radius + iVar21 * 0x14a)) {
            *(undefined4 *)(&thing_general_col_radius + iVar21 * 0xa5) =
                 (&thing_col_z_radius)[iVar21 * 0x14a];
            *(undefined4 *)((int)&thing_general_col_radius + iVar18 + 4) =
                 (&DAT_007ac114)[iVar21 * 0x14a];
          }
          if (*(int *)(&DAT_007ac3b0 + iVar18) == 1) {
            select_sec = select_sec + 0x11;
            (&thing_col_x_radius)[iVar21 * 0x14a] =
                 *(undefined4 *)(&thing_general_col_radius + iVar21 * 0xa5);
            (&DAT_007ac104)[iVar21 * 0x14a] =
                 *(undefined4 *)((int)&thing_general_col_radius + iVar18 + 4);
            (&thing_col_y_radius)[iVar21 * 0x14a] =
                 *(undefined4 *)(&thing_general_col_radius + iVar21 * 0xa5);
            (&DAT_007ac10c)[iVar21 * 0x14a] =
                 *(undefined4 *)((int)&thing_general_col_radius + iVar18 + 4);
            (&thing_col_z_radius)[iVar21 * 0x14a] =
                 *(undefined4 *)(&thing_general_col_radius + iVar21 * 0xa5);
            (&DAT_007ac114)[iVar21 * 0x14a] =
                 *(undefined4 *)((int)&thing_general_col_radius + iVar18 + 4);
            param_1 = select_sec;
          }
          else {
            if (*(int *)(&DAT_007ac3b0 + iVar18) == 2) goto LAB_0045b406;
            *(undefined4 *)(&thing_general_col_radius + iVar21 * 0xa5) = 0;
            *(undefined4 *)((int)&thing_general_col_radius + iVar18 + 4) = 0x3ff00000;
            (&thing_col_x_radius)[iVar21 * 0x14a] = 0;
            (&DAT_007ac104)[iVar21 * 0x14a] = 0x3ff00000;
            (&thing_col_y_radius)[iVar21 * 0x14a] = 0;
            (&DAT_007ac10c)[iVar21 * 0x14a] = 0x3ff00000;
            select_sec = select_sec + 0x11;
            (&thing_col_z_radius)[iVar21 * 0x14a] = 0;
            (&DAT_007ac114)[iVar21 * 0x14a] = 0x3ff00000;
            param_1 = select_sec;
          }
        }
        break;
      case 0x78:
        uVar19 = param_9 & 0xffff;
        if (uVar19 < 8) {
          select_sec = *(int *)(puVar27 + iVar25);
          iVar21 = *(int *)(&DAT_0081c264 + uVar19 * 0x3510);
          *(int *)(&DAT_0081c264 + uVar19 * 0x3510) = iVar21 + select_sec;
          if (0 < iVar21 + select_sec) {
            (&srcplayer_flags)[uVar19 * 0xd44] = (&srcplayer_flags)[uVar19 * 0xd44] | 0x20;
            tweak_srcplayer_status(uVar19);
            goto LAB_0045bfec;
          }
        }
        else if (uVar19 < 0x10c) {
          select_sec = *(int *)(puVar27 + iVar25);
          iVar18 = (uVar19 - 8) * 0x528;
          iVar21 = *(int *)(&DAT_007ac408 + iVar18);
          *(int *)(&DAT_007ac408 + iVar18) = iVar21 + select_sec;
          if (0 < iVar21 + select_sec) {
            *(uint *)(&srcthing_flags + iVar18) = *(uint *)(&srcthing_flags + iVar18) | 0x40;
            tweak_srcthing_status(uVar19 - 8);
            goto LAB_0045bfec;
          }
        }
        goto LAB_0045c36a;
      case 0x79:
        uVar19 = param_9 & 0xffff;
        if (uVar19 < 8) {
          *(undefined4 *)(&player_haze_brightness + uVar19 * 0x3510) =
               *(undefined4 *)(puVar27 + iVar25);
          tweak_srcplayer_status(uVar19);
        }
        else {
          if (0x10b < uVar19) goto LAB_0045c36a;
          *(undefined4 *)(&thing_haze_brightness + (uVar19 - 8) * 0x528) =
               *(undefined4 *)(puVar27 + iVar25);
          tweak_srcthing_status(uVar19 - 8);
        }
        goto LAB_0045bfec;
      case 0x7a:
        uVar19 = param_9 & 0xffff;
        if ((7 < uVar19) ||
           (iVar21 = *(int *)(puVar27 + iVar25), iVar18 = *(int *)(&DAT_0081c260 + uVar19 * 0x3510),
           *(int *)(&DAT_0081c260 + uVar19 * 0x3510) = iVar18 + iVar21, iVar18 + iVar21 < 1))
        goto LAB_0045c36a;
        select_sec = select_sec + 5;
        (&srcplayer_flags)[uVar19 * 0xd44] = (&srcplayer_flags)[uVar19 * 0xd44] | 0x10;
        param_1 = select_sec;
        break;
      case 0x7b:
        uVar19 = param_9 & 0xffff;
        if (uVar19 < 8) {
          (&srcplayer_flags)[uVar19 * 0xd44] = (&srcplayer_flags)[uVar19 * 0xd44] | 0xc0;
          tweak_srcplayer_status(uVar19);
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        else {
          select_sec = iVar25;
          if (uVar19 < 0x10c) {
            iVar21 = uVar19 - 8;
            if ((*(byte *)(&src_behavior_bits + iVar21 * 0x14a) & 0x40) == 0) {
              *(uint *)(&srcthing_flags + iVar21 * 0x528) =
                   *(uint *)(&srcthing_flags + iVar21 * 0x528) | 0x18;
              tweak_srcthing_status(iVar21);
              select_sec = param_1;
              puVar27 = selected_poly;
            }
          }
        }
        break;
      case 0x7c:
        uVar19 = param_9 & 0xffff;
        select_sec = iVar25;
        if (uVar19 < 8) {
          (&srcplayer_flags)[uVar19 * 0xd44] = (&srcplayer_flags)[uVar19 * 0xd44] & 0xffffff3f;
          tweak_srcplayer_status(uVar19);
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        break;
      case 0x7d:
        if (7 < (param_9 & 0xffff)) goto LAB_0045c36a;
        srcplayer_highest_weapon_with_ammo(param_9 & 0xffff,*(undefined4 *)(puVar27 + iVar25));
        goto LAB_0045bfec;
      case 0x7e:
        select_sec = iVar25;
        if ((param_9 & 0xffff) < 8) {
          srcplayer_next_weapon_with_ammo(param_9 & 0xffff);
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        break;
      case 0x7f:
        select_sec = iVar25;
        if ((param_9 & 0xffff) < 8) {
          srcplayer_prev_weapon_with_ammo(param_9 & 0xffff);
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        break;
      case 0x80:
        uVar19 = param_9 & 0xffff;
        if (7 < uVar19) goto LAB_0045c36a;
        if (*(int *)(puVar27 + iVar25) == 0) {
          select_sec = select_sec + 5;
          (&srcplayer_flags)[uVar19 * 0xd44] = (&srcplayer_flags)[uVar19 * 0xd44] & 0xfffffffe;
          param_1 = select_sec;
        }
        else {
          select_sec = select_sec + 5;
          (&srcplayer_flags)[uVar19 * 0xd44] = (&srcplayer_flags)[uVar19 * 0xd44] | 1;
          param_1 = select_sec;
        }
        break;
      case 0x81:
        uVar19 = param_9 & 0xffff;
        if (7 < uVar19) goto LAB_0045c36a;
        if (*(int *)(puVar27 + iVar25) == 0) {
          select_sec = select_sec + 5;
          (&srcplayer_flags)[uVar19 * 0xd44] = (&srcplayer_flags)[uVar19 * 0xd44] & 0xfffffffb;
          param_1 = select_sec;
        }
        else {
          select_sec = select_sec + 5;
          (&srcplayer_flags)[uVar19 * 0xd44] = (&srcplayer_flags)[uVar19 * 0xd44] | 4;
          param_1 = select_sec;
        }
        break;
      case 0x82:
        puVar30 = (undefined4 *)(puVar27 + iVar25);
        iVar25 = select_sec + 5;
        uVar19 = param_9 & 0xffff;
        if (7 < uVar19) goto LAB_0045c36a;
        uVar15 = 1 << ((byte)*puVar30 & 0x1f);
        if (*(int *)(puVar27 + iVar25) == 0) {
          select_sec = select_sec + 9;
          *(uint *)(&srcplayer_equipment + uVar19 * 0x3510) =
               *(uint *)(&srcplayer_equipment + uVar19 * 0x3510) & ~uVar15;
          param_1 = select_sec;
        }
        else {
          select_sec = select_sec + 9;
          *(uint *)(&srcplayer_equipment + uVar19 * 0x3510) =
               *(uint *)(&srcplayer_equipment + uVar19 * 0x3510) | uVar15;
          param_1 = select_sec;
        }
        break;
      case 0x83:
        if ((param_9 & 0xffff) < 8) {
          iVar21 = (param_9 & 0xffff) * 0x3510;
          *(undefined4 *)(&srcplayer_foot_front + iVar21) = *(undefined4 *)(puVar27 + iVar25);
          *(undefined4 *)(&DAT_0081be34 + iVar21) = *(undefined4 *)(puVar27 + select_sec + 5);
          *(undefined4 *)(&srcplayer_foot_back + iVar21) = *(undefined4 *)(puVar27 + select_sec + 9)
          ;
          *(undefined4 *)(&DAT_0081be3c + iVar21) = *(undefined4 *)(puVar27 + select_sec + 0xd);
          *(undefined4 *)(&srcplayer_foot_left + iVar21) =
               *(undefined4 *)(puVar27 + select_sec + 0x11);
          *(undefined4 *)(&DAT_0081be44 + iVar21) = *(undefined4 *)(puVar27 + select_sec + 0x15);
          *(undefined4 *)(&srcplayer_foot_right + iVar21) =
               *(undefined4 *)(puVar27 + select_sec + 0x19);
          *(undefined4 *)(&DAT_0081be4c + iVar21) = *(undefined4 *)(puVar27 + select_sec + 0x1d);
        }
LAB_0045a18a:
        select_sec = iVar25 + 0x20;
        param_1 = iVar25 + 0x20;
        break;
      case 0x84:
        uVar19 = param_9 & 0xffff;
        if (uVar19 < 8) {
          iVar21 = uVar19 * 0x3510;
          param_1 = select_sec + 0x11;
          *(undefined4 *)(&DAT_0081bff0 + iVar21) = *(undefined4 *)(puVar27 + iVar25);
          *(undefined4 *)(&DAT_0081bff4 + iVar21) = *(undefined4 *)(puVar27 + select_sec + 5);
          *(undefined4 *)(&DAT_0081bff8 + iVar21) = *(undefined4 *)(puVar27 + select_sec + 9);
          *(undefined4 *)(&DAT_0081bffc + iVar21) = *(undefined4 *)(puVar27 + select_sec + 0xd);
          select_sec = param_1;
        }
        else {
          if (0x10b < uVar19) goto LAB_0045b406;
          iVar21 = (uVar19 - 8) * 0x528;
          param_1 = select_sec + 0x11;
          *(undefined4 *)(&DAT_007ac160 + iVar21) = *(undefined4 *)(puVar27 + iVar25);
          *(undefined4 *)(&DAT_007ac164 + iVar21) = *(undefined4 *)(puVar27 + select_sec + 5);
          *(undefined4 *)(&DAT_007ac168 + iVar21) = *(undefined4 *)(puVar27 + select_sec + 9);
          *(undefined4 *)(&DAT_007ac16c + iVar21) = *(undefined4 *)(puVar27 + select_sec + 0xd);
          select_sec = param_1;
        }
        break;
      case 0x85:
        uVar19 = param_9 & 0xffff;
        if (7 < uVar19) goto LAB_0045c36a;
        if (*(int *)(puVar27 + iVar25) == 0) {
          select_sec = select_sec + 5;
          (&srcplayer_flags)[uVar19 * 0xd44] = (&srcplayer_flags)[uVar19 * 0xd44] & 0xfffffeff;
          param_1 = select_sec;
        }
        else {
          select_sec = select_sec + 5;
          (&srcplayer_flags)[uVar19 * 0xd44] = (&srcplayer_flags)[uVar19 * 0xd44] | 0x100;
          param_1 = select_sec;
        }
        break;
      case 0x86:
        uVar19 = param_9 & 0xffff;
        if (7 < uVar19) goto LAB_0045c36a;
        if (*(int *)(puVar27 + iVar25) == 0) {
          select_sec = select_sec + 5;
          (&srcplayer_flags)[uVar19 * 0xd44] = (&srcplayer_flags)[uVar19 * 0xd44] & 0xfffffdff;
          param_1 = select_sec;
        }
        else {
          select_sec = select_sec + 5;
          (&srcplayer_flags)[uVar19 * 0xd44] = (&srcplayer_flags)[uVar19 * 0xd44] | 0x200;
          param_1 = select_sec;
        }
        break;
      case 0x87:
        uVar19 = param_9 & 0xffff;
        if (uVar19 < 8) {
          if ((puVar27[iVar25] & 1) == 0) {
            uVar15 = (&srcplayer_flags)[uVar19 * 0xd44] | 0x40000;
          }
          else {
            uVar15 = (&srcplayer_flags)[uVar19 * 0xd44] & 0xfffbffff;
          }
          puVar22 = &srcplayer_flags + uVar19 * 0xd44;
          *puVar22 = uVar15;
          if ((puVar27[iVar25] & 2) == 0) {
            select_sec = select_sec + 5;
            *puVar22 = *puVar22 | 0x800;
            param_1 = select_sec;
          }
          else {
            select_sec = select_sec + 5;
            *puVar22 = *puVar22 & 0xfffff7ff;
            param_1 = select_sec;
          }
        }
        else {
          if (0x10b < uVar19) goto LAB_0045c36a;
          if (*(int *)(puVar27 + iVar25) == 0) {
            select_sec = select_sec + 5;
            *(uint *)(&srcthing_flags + (uVar19 - 8) * 0x528) =
                 *(uint *)(&srcthing_flags + (uVar19 - 8) * 0x528) | 4;
            param_1 = select_sec;
          }
          else {
            select_sec = select_sec + 5;
            *(uint *)(&srcthing_flags + (uVar19 - 8) * 0x528) =
                 *(uint *)(&srcthing_flags + (uVar19 - 8) * 0x528) & 0xfffffffb;
            param_1 = select_sec;
          }
        }
        break;
      case 0x88:
        uVar19 = param_9 & 0xffff;
        if (uVar19 < 8) {
          select_sec = *(int *)(puVar27 + iVar25);
          iVar21 = uVar19 * 0x3510;
          *(int *)(&DAT_0081c360 + iVar21) = select_sec;
          if ((-1 < select_sec) && (select_sec < num_equipment_types)) {
            generate_for_thing(*(undefined4 *)(&equipment_select_event + select_sec * 0x40),
                               (&srcplayer_sector_flags)[uVar19 * 0xd44],0,0,
                               *(undefined4 *)(&sector_px + uVar19 * 0x6a2),
                               *(undefined4 *)((int)&sector_px + iVar21 + 4),
                               *(undefined4 *)(&sector_py + uVar19 * 0x6a2),
                               *(undefined4 *)((int)&sector_py + iVar21 + 4),
                               *(undefined4 *)(&sector_pz + uVar19 * 0x6a2),
                               *(undefined4 *)((int)&sector_pz + iVar21 + 4),uVar19 - 0x10000);
            goto LAB_0045bfec;
          }
        }
        goto LAB_0045c36a;
      case 0x89:
        if (7 < (param_9 & 0xffff)) goto LAB_0045c36a;
        select_sec = select_sec + 5;
        (&DAT_0081c2d4)[(param_9 & 0xffff) * 0xd44] = *(undefined4 *)(puVar27 + iVar25);
        param_1 = select_sec;
        break;
      case 0x8a:
        uVar19 = param_9 & 0xffff;
        if ((7 < uVar19) && (uVar19 < 0x10c)) {
          wake_source_thing(uVar19 - 8);
          iVar25 = param_1;
          puVar27 = selected_poly;
          if (*(int *)(selected_poly + param_1) != 0) {
            local_74 = 0;
            piVar16 = &srcplayer_morale;
            iVar21 = param_1;
            do {
              if (((*(byte *)(piVar16 + -0x6c) & 1) != 0) &&
                 (*piVar16 == (&srcplayer_morale)[(uVar19 - 8) * 0x14a])) {
                wake_source_thing(local_74);
                iVar21 = param_1;
                puVar27 = selected_poly;
              }
              piVar16 = piVar16 + 0x14a;
              local_74 = local_74 + 1;
            } while ((int)piVar16 < 0x800230);
            select_sec = iVar21 + 4;
            param_1 = iVar21 + 4;
            break;
          }
        }
        goto LAB_0045c36a;
      case 0x8b:
        uVar19 = param_9 & 0xffff;
        if (uVar19 < 8) {
          srcplayer_kill(uVar19,uVar19);
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        else if ((int)(uVar19 - 8) < 0x104) {
          thing_kill(uVar19 - 8);
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        else {
          select_sec = iVar25;
          if ((299 < (int)(uVar19 - 0x10c)) && ((int)(uVar19 - 0x238) < 0x800)) {
            _matherr(uVar19 - 0x238);
            select_sec = param_1;
            puVar27 = selected_poly;
          }
        }
        break;
      case 0x8c:
        uVar15 = param_9 & 0xffff;
        uVar19 = param_9 & 0xffff;
        select_sec = iVar25;
        if (uVar15 < 8) {
          select_sec = 4;
          iVar21 = uVar15 * 0x3510;
          piVar16 = &front_shield_cur + uVar15 * 0xd44;
          do {
            iVar18 = *piVar16;
            piVar16 = piVar16 + 1;
            select_sec = select_sec + -1;
            (&curr_cash)[uVar15 * 0xd44] =
                 (&curr_cash)[uVar15 * 0xd44] + (iVar18 / 100) * shield_weight;
          } while (select_sec != 0);
          (&front_shield_cur)[uVar15 * 0xd44] = 0;
          (&back_shield_cur)[uVar15 * 0xd44] = 0;
          (&left_shield_cur)[uVar15 * 0xd44] = 0;
          (&right_shield_cur)[uVar15 * 0xd44] = 0;
          if (0 < num_ammo_types) {
            piVar24 = &ammo_rounds_per_clip;
            piVar16 = &ammo_available + uVar15 * 0xd44;
            select_sec = num_ammo_types;
            do {
              if (0 < *piVar16) {
                (&curr_cash)[uVar15 * 0xd44] =
                     (&curr_cash)[uVar15 * 0xd44] + (piVar24[1] * *piVar16) / *piVar24;
              }
              *piVar16 = 0;
              piVar16 = piVar16 + 1;
              piVar24 = piVar24 + 0xe;
              select_sec = select_sec + -1;
            } while (select_sec != 0);
          }
          select_sec = num_weapon_types;
          iVar23 = 0;
          iVar18 = 0;
          if (0 < num_weapon_types) {
            piVar16 = &DAT_0080fa44;
            do {
              if (((&weapon_bits)[uVar15 * 0xd44] & 1 << ((byte)iVar18 & 0x1f)) != 0) {
                (&curr_cash)[uVar15 * 0xd44] = (&curr_cash)[uVar15 * 0xd44] + *piVar16;
              }
              iVar18 = iVar18 + 1;
              piVar16 = piVar16 + 0xaa;
            } while (iVar18 < select_sec);
          }
          select_sec = num_equipment_types;
          (&weapon_bits)[uVar15 * 0xd44] = 0;
          (&DAT_0081c2d4)[uVar15 * 0xd44] = 0xffffffff;
          if (0 < select_sec) {
            puVar30 = &equipment_off_event;
            piVar16 = &DAT_0080fa44;
            do {
              uVar17 = 1 << ((byte)iVar23 & 0x1f);
              if (((&srcplayer_equipment_bits)[uVar15 * 0xd44] & uVar17) != 0) {
                (&curr_cash)[uVar15 * 0xd44] = (&curr_cash)[uVar15 * 0xd44] + *piVar16;
                if ((uVar17 & *(uint *)(&srcplayer_equipment + iVar21)) != 0) {
                  *(uint *)(&srcplayer_equipment + iVar21) =
                       *(uint *)(&srcplayer_equipment + iVar21) & ~uVar17;
                  generate_for_thing(*puVar30,(&srcplayer_sector_flags)[uVar15 * 0xd44],0,0,
                                     *(undefined4 *)(&sector_px + uVar15 * 0x6a2),
                                     *(undefined4 *)((int)&sector_px + iVar21 + 4),
                                     *(undefined4 *)(&sector_py + uVar15 * 0x6a2),
                                     *(undefined4 *)((int)&sector_py + iVar21 + 4),
                                     *(undefined4 *)(&sector_pz + uVar15 * 0x6a2),
                                     *(undefined4 *)((int)&sector_pz + iVar21 + 4),uVar19 - 0x10000)
                  ;
                }
              }
              iVar23 = iVar23 + 1;
              piVar16 = piVar16 + 0xaa;
              puVar30 = puVar30 + 0x10;
            } while (iVar23 < num_equipment_types);
          }
          (&srcplayer_equipment_bits)[uVar15 * 0xd44] = 0;
          *(undefined4 *)(&srcplayer_equipment + iVar21) = 0;
          *(undefined4 *)(&DAT_0081c360 + iVar21) = 0xffffffff;
          srcplayer_update_weapon_bits(uVar19);
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        break;
      case 0x8d:
        iVar21 = *(int *)(puVar27 + iVar25);
        param_1 = select_sec + 5;
        iVar23 = 0;
        select_sec = param_1;
        if (0 < num_scripts) {
          do {
            if ((&compiled_scripts)[iVar23] == iVar21) {
              (&script_event_id)[iVar23] =
                   (&script_event_id)[iVar23] & ~(1 << ((byte)param_9 & 0x1f));
            }
            iVar23 = iVar23 + 1;
          } while (iVar23 < iVar18);
        }
        break;
      case 0x8e:
        iVar21 = *(int *)(puVar27 + iVar25);
        param_1 = select_sec + 5;
        iVar23 = 0;
        select_sec = param_1;
        if (0 < num_scripts) {
          do {
            if ((&compiled_scripts)[iVar23] == iVar21) {
              (&script_event_id)[iVar23] = (&script_event_id)[iVar23] | 1 << ((byte)param_9 & 0x1f);
            }
            iVar23 = iVar23 + 1;
          } while (iVar23 < iVar18);
        }
        break;
      case 0x8f:
        uVar19 = param_9 & 0xffff;
        if (7 < uVar19) goto LAB_0045c3f6;
        param_1 = select_sec + 9;
        (&focal_adjust_mod)[uVar19 * 0xd44] = *(undefined4 *)(puVar27 + iVar25);
        (&DAT_0081bf9c)[uVar19 * 0xd44] = *(undefined4 *)(puVar27 + select_sec + 5);
        select_sec = param_1;
        break;
      case 0x90:
        uVar19 = param_9 & 0xffff;
        if ((uVar19 < 8) || (0x10b < uVar19)) goto LAB_0045c36a;
        select_sec = select_sec + 5;
        *(undefined4 *)(&DAT_007ac588 + (uVar19 - 8) * 0x528) = *(undefined4 *)(puVar27 + iVar25);
        param_1 = select_sec;
        break;
      case 0x91:
        if (7 < (param_9 & 0xffff)) goto LAB_0045b406;
        iVar21 = (param_9 & 0xffff) * 0x3510;
        param_1 = select_sec + 0x11;
        *(undefined4 *)(&DAT_0081c000 + iVar21) = *(undefined4 *)(puVar27 + iVar25);
        *(undefined4 *)(&DAT_0081c004 + iVar21) = *(undefined4 *)(puVar27 + select_sec + 5);
        *(undefined4 *)(&DAT_0081c008 + iVar21) = *(undefined4 *)(puVar27 + select_sec + 9);
        *(undefined4 *)(&DAT_0081c00c + iVar21) = *(undefined4 *)(puVar27 + select_sec + 0xd);
        select_sec = param_1;
        break;
      case 0x92:
        if (7 < (param_9 & 0xffff)) goto LAB_0045c3f6;
        iVar21 = (param_9 & 0xffff) * 0x3510;
        param_1 = select_sec + 9;
        *(undefined4 *)(&DAT_0081c010 + iVar21) = *(undefined4 *)(puVar27 + iVar25);
        *(undefined4 *)(&DAT_0081c014 + iVar21) = *(undefined4 *)(puVar27 + select_sec + 5);
        select_sec = param_1;
        break;
      case 0x93:
        if ((param_9 & 0xffff) < 8) {
          srcplayer_start_loop
                    (param_9 & 0xffff,*(undefined4 *)(puVar27 + iVar25),
                     *(undefined4 *)(puVar27 + select_sec + 5),
                     *(undefined4 *)(puVar27 + select_sec + 9),
                     *(undefined4 *)(puVar27 + select_sec + 0xd),
                     *(undefined4 *)(puVar27 + select_sec + 0x11),
                     *(undefined4 *)(puVar27 + select_sec + 0x15),
                     *(undefined4 *)(puVar27 + select_sec + 0x19));
          puVar27 = selected_poly;
        }
LAB_0045a5fc:
        select_sec = param_1 + 0x1c;
        param_1 = param_1 + 0x1c;
        break;
      case 0x94:
        if (7 < (param_9 & 0xffff)) goto LAB_0045c36a;
        srcplayer_stop_loop(param_9 & 0xffff,*(undefined4 *)(puVar27 + iVar25));
        goto LAB_0045bfec;
      case 0x95:
        uVar19 = param_9 & 0xffff;
        if ((uVar19 < 8) || (0x10b < uVar19)) goto LAB_0045aea9;
        if (0.0 <= *(double *)(puVar27 + iVar25)) {
          if (0.0 < *(double *)(puVar27 + iVar25)) {
            *(undefined4 *)(&strafe_acceleration + (uVar19 - 8) * 0x528) =
                 *(undefined4 *)(puVar27 + select_sec + 9);
          }
        }
        else {
          *(int *)(&strafe_acceleration + (uVar19 - 8) * 0x528) =
               -*(int *)(puVar27 + select_sec + 9);
        }
        iVar21 = (uVar19 - 8) * 0x528;
        param_1 = select_sec + 0x15;
        *(double *)(&DAT_007ac258 + iVar21) = ABS(*(double *)(puVar27 + iVar25));
        *(undefined4 *)(&DAT_007ac260 + iVar21) = *(undefined4 *)(puVar27 + select_sec + 0xd);
        *(undefined4 *)(&DAT_007ac264 + iVar21) = *(undefined4 *)(puVar27 + select_sec + 0x11);
        select_sec = param_1;
        break;
      case 0x96:
        uVar19 = param_9 & 0xffff;
        if ((7 < uVar19) && (uVar19 < 0x10c)) {
          if (0.0 <= *(double *)(puVar27 + iVar25)) {
            if (0.0 < *(double *)(puVar27 + iVar25)) {
              *(undefined4 *)(&z_strafe_acceleration + (uVar19 - 8) * 0x528) =
                   *(undefined4 *)(puVar27 + select_sec + 9);
            }
          }
          else {
            *(int *)(&z_strafe_acceleration + (uVar19 - 8) * 0x528) =
                 -*(int *)(puVar27 + select_sec + 9);
          }
          iVar21 = (uVar19 - 8) * 0x528;
          *(double *)(&DAT_007ac270 + iVar21) = ABS(*(double *)(puVar27 + iVar25));
          *(undefined4 *)(&DAT_007ac278 + iVar21) = *(undefined4 *)(puVar27 + select_sec + 0xd);
          *(undefined4 *)(&DAT_007ac27c + iVar21) = *(undefined4 *)(puVar27 + select_sec + 0x11);
        }
LAB_0045aea9:
        select_sec = select_sec + 0x15;
        param_1 = select_sec;
        break;
      case 0x97:
        uVar19 = param_9 & 0xffff;
        if ((uVar19 < 8) || (0x10b < uVar19)) goto LAB_0045c36a;
        iVar21 = *(int *)(puVar27 + iVar25);
        if (0 < iVar21) {
          iVar21 = iVar21 / 0x16;
          if (iVar21 < 1) {
            iVar21 = 1;
          }
          else if (0xef < iVar21) {
            iVar21 = 0xef;
          }
        }
        select_sec = select_sec + 5;
        *(int *)(&targetting_lag_multiplier + (uVar19 - 8) * 0x528) = iVar21;
        param_1 = select_sec;
        break;
      case 0x98:
        uVar19 = param_9 & 0xffff;
        if ((7 < uVar19) && (uVar19 < 0x10c)) {
          iVar21 = uVar19 - 8;
          (&DAT_007ac410)[iVar21 * 0x14a] = (uint)(byte)puVar27[iVar25];
          *(undefined4 *)(&DAT_007ac58c + iVar21 * 0x528) = 0;
          if (((&DAT_007ac410)[iVar21 * 0x14a] == 0xd) || ((&DAT_007ac410)[iVar21 * 0x14a] == 0x11))
          {
            *(undefined4 *)(&closest_target + iVar21 * 0x528) = 0xffffffff;
          }
        }
        select_sec = select_sec + 2;
        param_1 = select_sec;
        break;
      case 0x99:
        uVar19 = param_9 & 0xffff;
        select_sec = iVar25;
        if ((7 < uVar19) && (uVar19 < 0x10c)) {
          *(uint *)(&srcthing_flags + (uVar19 - 8) * 0x528) =
               *(uint *)(&srcthing_flags + (uVar19 - 8) * 0x528) | 2;
        }
        break;
      case 0x9a:
        uVar19 = param_9 & 0xffff;
        select_sec = iVar25;
        if (7 < uVar19) {
          if ((int)(uVar19 - 8) < 0x104) {
            delete_srcplayer(uVar19 - 8);
            select_sec = param_1;
            puVar27 = selected_poly;
          }
          else if ((299 < (int)(uVar19 - 0x10c)) && ((int)(uVar19 - 0x238) < 0x800)) {
            _matherr(uVar19 - 0x238);
            select_sec = param_1;
            puVar27 = selected_poly;
          }
        }
        break;
      case 0x9b:
        uVar19 = param_9 & 0xffff;
        if ((uVar19 < 8) || (0x10b < uVar19)) goto LAB_0045c3f6;
        param_1 = select_sec + 9;
        *(undefined4 *)(&srcplayer_move_speed + (uVar19 - 8) * 0x528) =
             *(undefined4 *)(puVar27 + select_sec + 1);
        *(undefined4 *)(&DAT_007ac124 + (uVar19 - 8) * 0x528) =
             *(undefined4 *)(puVar27 + select_sec + 5);
        select_sec = param_1;
        break;
      case 0x9c:
        uVar19 = param_9 & 0xffff;
        if (7 < uVar19) goto LAB_0045c36a;
        if (*(int *)(puVar27 + iVar25) == 0) {
          select_sec = select_sec + 5;
          (&srcplayer_flags)[uVar19 * 0xd44] = (&srcplayer_flags)[uVar19 * 0xd44] & 0xfffdffff;
          param_1 = select_sec;
        }
        else {
          select_sec = select_sec + 5;
          (&srcplayer_flags)[uVar19 * 0xd44] = (&srcplayer_flags)[uVar19 * 0xd44] | 0x20000;
          param_1 = select_sec;
        }
        break;
      case 0x9d:
        uVar19 = param_9 & 0xffff;
        if (7 < uVar19) goto LAB_0045b406;
        param_1 = select_sec + 0x11;
        *(undefined4 *)(&srcplayer_targeted_x_modifier + uVar19 * 0x6a2) =
             *(undefined4 *)(puVar27 + iVar25);
        *(undefined4 *)((int)&srcplayer_targeted_x_modifier + uVar19 * 0x3510 + 4) =
             *(undefined4 *)(puVar27 + select_sec + 5);
        *(undefined4 *)(&srcplayer_targeted_z_modifier + uVar19 * 0x6a2) =
             *(undefined4 *)(puVar27 + select_sec + 9);
        *(undefined4 *)((int)&srcplayer_targeted_z_modifier + uVar19 * 0x3510 + 4) =
             *(undefined4 *)(puVar27 + select_sec + 0xd);
        select_sec = param_1;
        break;
      case 0x9e:
        iVar21 = *(int *)(puVar27 + iVar25);
        param_1 = select_sec + 5;
        iVar18 = 0;
        select_sec = param_1;
        if (0 < iVar21) {
          do {
            if (((iVar18 < 0x20) && (uVar19 = param_9 & 0xffff, 7 < uVar19)) && (uVar19 < 0x10c)) {
              *(undefined4 *)(&DAT_007ac504 + (iVar18 + (uVar19 - 8) * 0x14a) * 4) =
                   *(undefined4 *)(puVar27 + param_1);
            }
            param_1 = param_1 + 4;
            iVar18 = iVar18 + 1;
            select_sec = param_1;
          } while (iVar18 < iVar21);
        }
        break;
      case 0x9f:
        uVar19 = param_9 & 0xffff;
        if ((uVar19 < 8) || (0x10b < uVar19)) goto LAB_0045c36a;
        select_sec = select_sec + 5;
        *(undefined4 *)(&src_path_index + (uVar19 - 8) * 0x528) = *(undefined4 *)(puVar27 + iVar25);
        param_1 = select_sec;
        break;
      case 0xa0:
        uVar19 = param_9 & 0xffff;
        if ((uVar19 < 8) || (0x10b < uVar19)) goto LAB_0045c36a;
        select_sec = select_sec + 5;
        (&src_behavior_bits)[(uVar19 - 8) * 0x14a] =
             (&src_behavior_bits)[(uVar19 - 8) * 0x14a] & *(uint *)(puVar27 + iVar25);
        param_1 = select_sec;
        break;
      case 0xa1:
        uVar19 = param_9 & 0xffff;
        if ((uVar19 < 8) || (0x10b < uVar19)) goto LAB_0045c36a;
        select_sec = select_sec + 5;
        (&src_behavior_bits)[(uVar19 - 8) * 0x14a] =
             (&src_behavior_bits)[(uVar19 - 8) * 0x14a] | *(uint *)(puVar27 + iVar25);
        param_1 = select_sec;
        break;
      case 0xa2:
        uVar19 = param_9 & 0xffff;
        if ((uVar19 < 8) || (0x10b < uVar19)) goto LAB_0045c36a;
        select_sec = select_sec + 5;
        (&srcplayer_extra_bits)[(uVar19 - 8) * 0x14a] =
             (&srcplayer_extra_bits)[(uVar19 - 8) * 0x14a] & *(uint *)(puVar27 + iVar25);
        param_1 = select_sec;
        break;
      case 0xa3:
        uVar19 = param_9 & 0xffff;
        if ((uVar19 < 8) || (0x10b < uVar19)) goto LAB_0045c36a;
        select_sec = select_sec + 5;
        (&srcplayer_extra_bits)[(uVar19 - 8) * 0x14a] =
             (&srcplayer_extra_bits)[(uVar19 - 8) * 0x14a] | *(uint *)(puVar27 + iVar25);
        param_1 = select_sec;
        break;
      case 0xa4:
        targetting_lag_adder = *(int *)(puVar27 + iVar25) / 0x16;
        _random_offsets_scaler = *(undefined8 *)(puVar27 + select_sec + 5);
        _random_offsets_adder = *(undefined8 *)(puVar27 + select_sec + 0xd);
        select_sec = select_sec + 0x15;
        param_1 = select_sec;
        break;
      case 0xa5:
        _player_target_multiplier = *(undefined8 *)(puVar27 + iVar25);
        _player_target_adder = *(undefined8 *)(puVar27 + select_sec + 9);
        select_sec = select_sec + 0x11;
        param_1 = select_sec;
        break;
      case 0xa6:
        select_sec = select_sec + 5;
        do {
          param_1 = select_sec;
        } while (LevelTicksTotal < *(int *)(puVar27 + iVar25) + LevelTicksTotal);
        break;
      case 0xa7:
        refresh_screen();
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0xa8:
        param_1 = select_sec + 5;
        set_deathmatch_start
                  (*(undefined4 *)(puVar27 + iVar25),*(undefined4 *)(puVar27 + param_1),
                   *(undefined4 *)(puVar27 + select_sec + 9),
                   *(undefined4 *)(puVar27 + select_sec + 0xd),
                   *(undefined4 *)(puVar27 + select_sec + 0x11),
                   *(undefined4 *)(puVar27 + select_sec + 0x15),
                   *(undefined4 *)(puVar27 + select_sec + 0x19),
                   *(undefined4 *)(puVar27 + select_sec + 0x1d),
                   *(undefined4 *)(puVar27 + select_sec + 0x21),
                   *(undefined4 *)(puVar27 + select_sec + 0x25));
        param_1 = param_1 + 0x24;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0xa9:
        param_1 = select_sec + 5;
        set_player_start(*(undefined4 *)(puVar27 + iVar25),*(undefined4 *)(puVar27 + param_1),
                         *(undefined4 *)(puVar27 + select_sec + 9),
                         *(undefined4 *)(puVar27 + select_sec + 0xd),
                         *(undefined4 *)(puVar27 + select_sec + 0x11),
                         *(undefined4 *)(puVar27 + select_sec + 0x15),
                         *(undefined4 *)(puVar27 + select_sec + 0x19),
                         *(undefined4 *)(puVar27 + select_sec + 0x1d),
                         *(undefined4 *)(puVar27 + select_sec + 0x21),
                         *(undefined4 *)(puVar27 + select_sec + 0x25));
        param_1 = param_1 + 0x24;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0xaa:
        iVar21 = define_weapons(&param_1);
        goto joined_r0x0045be9b;
      case 0xab:
        iVar21 = define_ammo(&param_1);
        goto joined_r0x0045be9b;
      case 0xac:
        iVar21 = define_player_types(&param_1);
        goto joined_r0x0045be9b;
      case 0xad:
        armor_depletion_rate = *(undefined4 *)(puVar27 + iVar25);
        virus_texture_id = *(undefined4 *)(puVar27 + select_sec + 5);
        virus_sample_name = *(undefined4 *)(puVar27 + select_sec + 9);
        virus_volume = *(undefined4 *)(puVar27 + select_sec + 0xd);
        virus_priority = *(undefined4 *)(puVar27 + select_sec + 0x11);
        iVar25 = select_sec + 0x15;
        _virus_sound_decay = *(undefined8 *)(puVar27 + iVar25);
LAB_0045c3f6:
        select_sec = iVar25 + 8;
        param_1 = iVar25 + 8;
        break;
      case 0xae:
        item_regen_sob_ptr = *(undefined4 *)(puVar27 + iVar25);
        _regen_mrkr_scroll_speed = *(undefined8 *)(puVar27 + select_sec + 5);
        _regen_mrkr_speed_decay = *(undefined8 *)(puVar27 + select_sec + 0xd);
        select_sec = select_sec + 0x15;
        param_1 = select_sec;
        break;
      case 0xaf:
        iVar21 = define_equipment(&param_1);
        goto joined_r0x0045be9b;
      case 0xb0:
        shield_weight = *(int *)(puVar27 + iVar25);
        shield_cost = *(undefined4 *)(puVar27 + select_sec + 5);
        iVar25 = select_sec + 5;
        goto LAB_0045c36a;
      case 0xb1:
        define_ammo(*(undefined4 *)(puVar27 + iVar25),param_6,param_7,param_8,gm_mem_loc - param_2);
        iVar25 = param_1;
LAB_0045be82:
        param_1 = iVar25 + 4;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0xb2:
        select_sec = (param_9 & 0xffff) - 8;
        if (((-1 < select_sec) && (select_sec < 0x104)) &&
           ((iVar21 = (&srcplayer_morale)[select_sec * 0x14a], -1 < iVar21 && (iVar21 < 0x20)))) {
          iVar18 = (&DAT_005e41f0)[iVar21] + *(int *)(puVar27 + iVar25);
          (&DAT_005e41f0)[iVar21] = iVar18;
          if (iVar18 < 5000) {
            iVar21 = random();
            if ((iVar18 * 100) / 5000 <= iVar21 % 100) {
              adjust_sourceplayer_morale((&srcplayer_morale)[select_sec * 0x14a]);
            }
            goto LAB_0045bfec;
          }
        }
LAB_0045c36a:
        select_sec = iVar25 + 4;
        param_1 = iVar25 + 4;
        break;
      case 0xb3:
        define_film(puVar27 + select_sec + 0xd,*(undefined4 *)(puVar27 + iVar25),
                    *(undefined4 *)(puVar27 + select_sec + 5),0,
                    *(undefined4 *)(puVar27 + select_sec + 9),0);
        param_1 = param_1 + 0xc;
LAB_0045c028:
        script_handle_name(&param_1);
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0xb4:
        play_film();
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0xb5:
        stop_film();
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0xb6:
        rewind_film();
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0xb7:
        add_switch(*(undefined4 *)(puVar27 + iVar25),*(undefined4 *)(puVar27 + select_sec + 5),
                   *(undefined4 *)(puVar27 + select_sec + 9),
                   *(undefined4 *)(puVar27 + select_sec + 0xd),
                   *(undefined4 *)(puVar27 + select_sec + 0x11),
                   *(undefined4 *)(puVar27 + select_sec + 0x15),
                   *(undefined4 *)(puVar27 + select_sec + 0x19),
                   *(undefined4 *)(puVar27 + select_sec + 0x1d));
        param_1 = param_1 + 0x20;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0xb8:
        add_door(*(undefined4 *)(puVar27 + iVar25),*(undefined4 *)(puVar27 + select_sec + 5),
                 *(undefined4 *)(puVar27 + select_sec + 9),
                 *(undefined4 *)(puVar27 + select_sec + 0xd),
                 *(undefined4 *)(puVar27 + select_sec + 0x11),
                 *(undefined4 *)(puVar27 + select_sec + 0x15),
                 *(undefined4 *)(puVar27 + select_sec + 0x19),
                 *(undefined4 *)(puVar27 + select_sec + 0x1d),
                 *(undefined4 *)(puVar27 + select_sec + 0x21),
                 *(undefined4 *)(puVar27 + select_sec + 0x25),
                 *(undefined4 *)(puVar27 + select_sec + 0x29),
                 *(undefined4 *)(puVar27 + select_sec + 0x2d),
                 *(undefined4 *)(puVar27 + select_sec + 0x31),
                 *(undefined4 *)(puVar27 + select_sec + 0x35),
                 *(undefined4 *)(puVar27 + select_sec + 0x39),
                 *(undefined4 *)(puVar27 + select_sec + 0x3d),
                 *(undefined4 *)(puVar27 + select_sec + 0x41),
                 *(undefined4 *)(puVar27 + select_sec + 0x45),
                 *(undefined4 *)(puVar27 + select_sec + 0x49),
                 *(undefined4 *)(puVar27 + select_sec + 0x4d),
                 *(undefined4 *)(puVar27 + select_sec + 0x51),
                 *(undefined4 *)(puVar27 + select_sec + 0x55),
                 *(undefined4 *)(puVar27 + select_sec + 0x59),
                 *(undefined4 *)(puVar27 + select_sec + 0x5d),
                 *(undefined4 *)(puVar27 + select_sec + 0x61),
                 *(undefined4 *)(puVar27 + select_sec + 0x65),
                 *(undefined4 *)(puVar27 + select_sec + 0x69),
                 *(undefined4 *)(puVar27 + select_sec + 0x6d),
                 *(undefined4 *)(puVar27 + select_sec + 0x71),
                 *(undefined4 *)(puVar27 + select_sec + 0x75),
                 *(undefined4 *)(puVar27 + select_sec + 0x79),
                 *(undefined4 *)(puVar27 + select_sec + 0x7d),
                 *(undefined4 *)(puVar27 + select_sec + 0x81),
                 *(undefined4 *)(puVar27 + select_sec + 0x85),
                 *(undefined4 *)(puVar27 + select_sec + 0x89),
                 *(undefined4 *)(puVar27 + select_sec + 0x8d),
                 *(undefined4 *)(puVar27 + select_sec + 0x91),
                 *(undefined4 *)(puVar27 + select_sec + 0x95),
                 *(undefined4 *)(puVar27 + select_sec + 0x99),
                 *(undefined4 *)(puVar27 + select_sec + 0x9d),
                 *(undefined4 *)(puVar27 + select_sec + 0xa1),
                 *(undefined4 *)(puVar27 + select_sec + 0xa5),
                 *(undefined4 *)(puVar27 + select_sec + 0xa9));
        param_1 = param_1 + 0xac;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0xb9:
        iVar21 = gm_mem_loc - param_2;
        uVar8 = *(undefined4 *)(puVar27 + select_sec + 0x25);
        uVar12 = *(undefined4 *)(puVar27 + select_sec + 0x21);
        uVar13 = *(undefined4 *)(puVar27 + select_sec + 0x1d);
        uVar45 = *(undefined4 *)(puVar27 + select_sec + 0x19);
        uVar39 = *(undefined4 *)(puVar27 + select_sec + 0x15);
        uVar37 = *(undefined4 *)(puVar27 + select_sec + 0x11);
        uVar35 = *(undefined4 *)(puVar27 + select_sec + 0xd);
        uVar47 = *(undefined4 *)(puVar27 + select_sec + 9);
        uVar44 = *(undefined4 *)(puVar27 + select_sec + 5);
        uVar43 = *(undefined4 *)(puVar27 + iVar25);
LAB_00459b45:
        script_add_named_item
                  (uVar43,uVar44,uVar47,uVar35,uVar37,uVar39,uVar45,uVar13,uVar12,uVar8,iVar21,
                   param_9 & 0xffff);
        goto LAB_00459b4d;
      case 0xba:
        iVar21 = *(int *)(puVar27 + select_sec + 5);
        iVar18 = *(int *)(puVar27 + select_sec + 9);
        param_1 = select_sec + 0xd;
        select_sec = thing_set_morale(*(undefined4 *)(puVar27 + iVar25));
        if (((select_sec != 0) && (iVar21 <= DAT_0083d62c)) && (DAT_0083d62c <= iVar18)) {
          iVar21 = gm_mem_loc - param_2;
          uVar8 = *(undefined4 *)(selected_poly + param_1 + 0x24);
          uVar12 = *(undefined4 *)(selected_poly + param_1 + 0x20);
          uVar13 = *(undefined4 *)(selected_poly + param_1 + 0x1c);
          uVar45 = *(undefined4 *)(selected_poly + param_1 + 0x18);
          uVar39 = *(undefined4 *)(selected_poly + param_1 + 0x14);
          uVar37 = *(undefined4 *)(selected_poly + param_1 + 0x10);
          uVar35 = *(undefined4 *)(selected_poly + param_1 + 0xc);
          uVar47 = *(undefined4 *)(selected_poly + param_1 + 8);
          uVar44 = *(undefined4 *)(selected_poly + param_1 + 4);
          uVar43 = *(undefined4 *)(selected_poly + param_1);
          goto LAB_00459b45;
        }
LAB_00459b4d:
        param_1 = param_1 + 0x28;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0xbb:
        add_sound_source(*(undefined4 *)(puVar27 + iVar25),*(undefined4 *)(puVar27 + select_sec + 5)
                         ,*(undefined4 *)(puVar27 + select_sec + 9),
                         *(undefined4 *)(puVar27 + select_sec + 0xd),
                         *(undefined4 *)(puVar27 + select_sec + 0x11),
                         *(undefined4 *)(puVar27 + select_sec + 0x15),
                         *(undefined4 *)(puVar27 + select_sec + 0x19));
        param_1 = param_1 + 0x1c;
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0xbc:
        iVar21 = script_add_lift(&param_1);
joined_r0x0045be9b:
        select_sec = param_1;
        puVar27 = selected_poly;
        if (iVar21 != 0) {
          return;
        }
        break;
      case 0xbd:
        select_sec = iVar25;
        if ((((byte)mp_game_flags & 0x10) == 0) && (uVar19 = param_9 & 0xffff, uVar19 < 8)) {
          if (((&tank_screen)[uVar19 * 0xd44] != 0) && ((&tank_screen)[uVar19 * 0xd44] != 7)) {
            (&tank_screen)[uVar19 * 0xd44] = 2;
          }
        }
        break;
      case 0xbe:
        uVar19 = param_9 & 0xffff;
        select_sec = iVar25;
        if (uVar19 < 8) {
          if (((&tank_screen)[uVar19 * 0xd44] != 0) && ((&tank_screen)[uVar19 * 0xd44] != 7)) {
            (&tank_screen)[uVar19 * 0xd44] = 3;
          }
        }
        break;
      case 0xbf:
        uVar19 = param_9 & 0xffff;
        select_sec = iVar25;
        if (uVar19 < 8) {
          if (((&tank_screen)[uVar19 * 0xd44] != 0) && ((&tank_screen)[uVar19 * 0xd44] != 7)) {
            (&tank_screen)[uVar19 * 0xd44] = 4;
          }
        }
        break;
      case 0xc0:
        uVar19 = param_9 & 0xffff;
        select_sec = iVar25;
        if (((uVar19 < 8) && ((&tank_screen)[uVar19 * 0xd44] != 0)) &&
           ((&tank_screen)[uVar19 * 0xd44] != 7)) {
          show_tank_save_screen(uVar19);
          select_sec = param_1;
          puVar27 = selected_poly;
        }
        break;
      case 0xc1:
        uVar19 = param_9 & 0xffff;
        select_sec = iVar25;
        if (uVar19 < 8) {
          if (((&tank_screen)[uVar19 * 0xd44] != 0) && ((&tank_screen)[uVar19 * 0xd44] != 7)) {
            (&tank_screen)[uVar19 * 0xd44] = 6;
          }
        }
        break;
      case 0xc2:
        menu_visible = 3;
        show_help_screen(1);
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0xc3:
        menu_visible = 2;
        show_help_screen(1);
        select_sec = param_1;
        puVar27 = selected_poly;
        break;
      case 0xc4:
        if (num_locations < 200) {
          iVar21 = num_locations * 0x28;
          param_1 = select_sec + 0x29;
          (&thing_loc_handle)[num_locations * 10] = *(undefined4 *)(puVar27 + iVar25);
          (&thing_new_loc_x)[num_locations * 10] = *(undefined4 *)(puVar27 + select_sec + 5);
          (&thing_new_loc_y)[num_locations * 10] = *(undefined4 *)(puVar27 + select_sec + 9);
          (&thing_new_loc_z)[num_locations * 10] = *(undefined4 *)(puVar27 + select_sec + 0xd);
          *(undefined4 *)(&loc_pitch + num_locations * 5) =
               *(undefined4 *)(puVar27 + select_sec + 0x11);
          *(undefined4 *)((int)&loc_pitch + iVar21 + 4) =
               *(undefined4 *)(puVar27 + select_sec + 0x15);
          *(undefined4 *)(&loc_roll + num_locations * 5) =
               *(undefined4 *)(puVar27 + select_sec + 0x19);
          *(undefined4 *)((int)&loc_roll + iVar21 + 4) =
               *(undefined4 *)(puVar27 + select_sec + 0x1d);
          *(undefined4 *)(&loc_yaw + num_locations * 5) =
               *(undefined4 *)(puVar27 + select_sec + 0x21);
          *(undefined4 *)((int)&loc_yaw + iVar21 + 4) = *(undefined4 *)(puVar27 + select_sec + 0x25)
          ;
          select_sec = param_1;
          num_locations = num_locations + 1;
        }
        else {
          log_message(s_Maximum_number_of_defined_locati_004b81b0,200);
          select_sec = param_1 + 0x28;
          puVar27 = selected_poly;
          param_1 = param_1 + 0x28;
        }
        break;
      case 0xc5:
        iVar21 = *(int *)(puVar27 + iVar25);
        param_1 = select_sec + 5;
        iVar18 = 0;
        select_sec = param_1;
        if (0 < num_locations) {
          piVar24 = &thing_loc_handle;
          piVar16 = &thing_loc_handle + num_locations * 10;
          iVar23 = num_locations;
          do {
            if (*piVar24 == iVar21) {
              num_locations = iVar23 + -1;
              piVar16 = piVar16 + -10;
              iVar23 = num_locations;
              if (iVar18 < num_locations) {
                iVar18 = iVar18 + -1;
                piVar26 = piVar16;
                piVar31 = piVar24;
                for (iVar23 = 10; iVar23 != 0; iVar23 = iVar23 + -1) {
                  *piVar31 = *piVar26;
                  piVar26 = piVar26 + 1;
                  piVar31 = piVar31 + 1;
                }
                piVar24 = piVar24 + -10;
                iVar23 = num_locations;
                puVar27 = selected_poly;
              }
            }
            iVar18 = iVar18 + 1;
            piVar24 = piVar24 + 10;
          } while (iVar18 < iVar23);
        }
        break;
      case 0xc6:
        iVar21 = 0;
        do {
          if ((-1 < *(int *)((int)&num_sleeping_scripts + iVar21)) &&
             ((*(uint *)((int)&DAT_005b29c8 + iVar21) & 0xffff) == (param_9 & 0xffff))) {
            *(undefined4 *)((int)&num_sleeping_scripts + iVar21) = 0xffffffff;
          }
          iVar21 = iVar21 + 4;
          select_sec = iVar25;
        } while (iVar21 < 0x400);
        break;
      case 199:
        if ((game_hostmode == 1) && (side_screen != 2)) {
          uVar8 = script_if_handle2();
          select_sec = script_check_sos(&param_1,param_2,iVar21,param_4,param_5,param_6,param_7,
                                        param_8,&param_9,uVar8);
        }
        else {
          select_sec = script_run_sos(&param_1,param_2,iVar21,param_4,param_5,param_6,param_7,
                                      param_8,&param_9);
          if (game_hostmode != 1) {
            script_if(select_sec);
          }
        }
        iVar25 = param_1;
        if (select_sec != 0) goto LAB_0045be82;
        select_sec = param_1 + *(int *)(selected_poly + param_1);
        puVar27 = selected_poly;
        param_1 = param_1 + *(int *)(selected_poly + param_1);
        break;
      case 200:
        select_sec = iVar25 + *(int *)(puVar27 + iVar25);
        param_1 = iVar25 + *(int *)(puVar27 + iVar25);
        break;
      default:
        log_message(s_Script_Internal_Error:_Unknown_p_004b8098);
        return;
      case 0xca:
        if (7 < (param_9 & 0xffff)) goto LAB_0045c36a;
        request_player_type(param_9 & 0xffff,*(undefined4 *)(puVar27 + iVar25),0,0,0,0,0,0);
LAB_0045bfec:
        select_sec = param_1 + 4;
        puVar27 = selected_poly;
        param_1 = param_1 + 4;
      }
LAB_0045c41b:
      if (0x2ffff < select_sec) {
        log_message(s_Internal_Error:_end_of_code_reac_004b8170);
        return;
      }
    }
  }
  else {
    log_message(s_Internal_Error:_end_of_code_reac_004b8170);
  }
switchD_004574d4_exit_event:
  return;
}
