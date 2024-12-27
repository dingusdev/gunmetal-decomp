char * pre_direct_draw_create(int param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *unaff_ESI;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  undefined4 *local_18 [2];
  int iStack_10;
  undefined4 uStack_c;
  
  if (dd_display_mode == (int *)0x0) {
    iVar3 = DirectDrawCreate(0,local_18,0);
    if (iVar3 != 0) {
      return s_Unable_to_Pre_Direct_Draw_Create_004a6240;
    }
    iVar3 = (**(code **)*local_18[0])(local_18[0],&DOUBLE_004a1858,&dd_display_mode);
    if (iVar3 != 0) {
      return s_Unable_to_Pre_Direct_Draw_Query_I_004a6214;
    }
    (**(code **)(*unaff_ESI + 8))(unaff_ESI);
    param_1 = (**(code **)(*dd_display_mode + 0x50))(dd_display_mode,uStack_c,0x53);
    if (param_1 != 0) {
      return s_Unable_to_Pre_Set_Cooperative_Le_004a61f0;
    }
  }
  (**(code **)(*dd_display_mode + 0x20))(dd_display_mode,3,0,0,dd_display_mode_detect);
  if (param_1 != 0) {
    return s_Unable_to_Determine_Display_Mode_004a61c4;
  }
  if ((vid_card_setting & 0x800U) != 0) goto LAB_00406181;
  iVar3 = win_check_glide_2x(s_glide2x_dll_004a61b8);
  if (iVar3 == 0) {
    iVar3 = glidelibinit();
    if (iVar3 != 0) {
      log_message(s_Error_code_of__ld_from_glidelibi_004a6190,iVar3);
      goto LAB_004060ab;
    }
  }
  else {
LAB_004060ab:
    vid_card_setting = vid_card_setting | 0x800;
  }
  if ((vid_card_setting & 0x800U) == 0) {
    (*grGlideInit)();
    iVar3 = (*grSstQueryHardware)(&GlideHWConfig);
    if (iVar3 == 0) {
      glide_active = 0;
    }
    else {
      iVar3 = 800;
      iStack_10 = 600;
      if ((DAT_004c050c == 0) && (_DAT_004c0510 < 4)) {
        iVar3 = 0x280;
        iStack_10 = 0x1e0;
      }
      piVar6 = &INT_004a6114;
      piVar4 = &setting_res_y + DAT_004c05bc * 5;
      do {
        if (((((int)piVar4 < 0x4c04ec) && (iVar5 = piVar6[-1], 0x13f < iVar5)) && (iVar5 <= iVar3))
           && ((iVar1 = *piVar6, 199 < iVar1 && (iVar1 <= iStack_10)))) {
          piVar4[-1] = iVar5;
          *piVar4 = iVar1;
          piVar4[1] = 0x20;
          piVar4[2] = 0;
          piVar4[3] = 0x804;
          DAT_004c05bc = DAT_004c05bc + 1;
          piVar4 = piVar4 + 5;
        }
        piVar6 = piVar6 + 3;
      } while ((int)piVar6 < 0x4a6174);
      (*grSstSelect)(0);
      glide_active = 1;
    }
  }
LAB_00406181:
  iStack_10 = DAT_004c05bc + -1;
  iVar3 = DAT_004c05bc + -1;
  do {
    bVar2 = true;
    iVar5 = iVar3;
    if (0 < iVar3) {
      piVar4 = &sw_video_mode;
      do {
        piVar6 = piVar4 + 3;
        if ((*piVar6 * 0x2000 + piVar4[4]) * 0x40 + piVar4[5] <
            (piVar4[-2] * 0x2000 + piVar4[-1]) * 0x40 + *piVar4) {
          piVar7 = piVar4 + -2;
          piVar8 = (int *)&stack0xffffffd8;
          for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
            *piVar8 = *piVar7;
            piVar7 = piVar7 + 1;
            piVar8 = piVar8 + 1;
          }
          piVar7 = piVar6;
          piVar8 = piVar4 + -2;
          for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
            *piVar8 = *piVar7;
            piVar7 = piVar7 + 1;
            piVar8 = piVar8 + 1;
          }
          piVar7 = (int *)&stack0xffffffd8;
          for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
            *piVar6 = *piVar7;
            piVar7 = piVar7 + 1;
            piVar6 = piVar6 + 1;
          }
          bVar2 = false;
        }
        piVar4 = piVar4 + 5;
        iVar3 = iVar3 + -1;
        iVar5 = iStack_10;
      } while (iVar3 != 0);
    }
    iVar3 = iVar5;
  } while (!bVar2);
  return (char *)0x0;
}
