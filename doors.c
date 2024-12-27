void update_door_positions(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  
  iVar2 = 0;
  if (0 < num_doors) {
    piVar1 = &DAT_00838230;
    do {
      if (((piVar1[-10] & 0xfU) != 0) && ((piVar1[-10] & 0xfU) < 4)) {
        *piVar1 = piVar1[-1];
        if (piVar1[-4] == 0) {
          iVar4 = piVar1[-2];
          iVar3 = piVar1[-3];
          dVar7 = 0.0;
          dVar6 = 0.0;
          dVar5 = 0.0;
        }
        else {
          iVar4 = piVar1[1] * param_1 * piVar1[-4] + piVar1[-1];
          *piVar1 = iVar4;
          if (iVar4 < 0) {
            *piVar1 = 0;
          }
          if (0xffff < *piVar1) {
            *piVar1 = 0xffff;
          }
          iVar4 = piVar1[-2];
          dVar5 = (double)(*piVar1 - piVar1[-1]) * 1.525902189669642e-05;
          dVar7 = (*(double *)(piVar1 + -0x1a) - *(double *)(piVar1 + -0x20)) * dVar5;
          dVar6 = (*(double *)(piVar1 + -0x1c) - *(double *)(piVar1 + -0x22)) * dVar5;
          iVar3 = piVar1[-3];
          dVar5 = (*(double *)(piVar1 + -0x1e) - *(double *)(piVar1 + -0x24)) * dVar5;
        }
        check_to_calc_door_bounding_box(iVar3,iVar4,dVar5,dVar6,dVar7);
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 0x2e;
    } while (iVar2 < num_doors);
  }
  return;
}



void synch_doors(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar5 = 0;
  if (0 < num_doors) {
    piVar6 = &door_position;
    do {
      if (((piVar6[-9] & 0xfU) != 0) && ((piVar6[-9] & 0xfU) < 4)) {
        iVar4 = piVar6[-3];
        if (iVar4 < -9) {
          piVar6[-3] = iVar4 + 10;
        }
        else if (iVar4 < 10) {
          if (iVar4 == 0) {
            if ((0 < piVar6[4]) &&
               (iVar3 = piVar6[4] - param_1, piVar6[4] = iVar3, iVar4 = setting_on, iVar3 < 1)) {
              piVar6[4] = 0;
              piVar6[-3] = -1;
              if ((iVar4 != 0) && (iVar4 = find_sector_3d(piVar6[-2],piVar6[-1]), iVar4 != 0)) {
                uVar2 = __ftol(piVar6[-0xb],piVar6[-10]);
                uVar2 = __ftol(uVar2);
                uVar2 = __ftol(uVar2);
                play_door_sound(piVar6[8],piVar6[5],0x2b11,1000,uVar2);
              }
            }
          }
          else {
            puVar1 = (undefined4 *)find_sector_3d(piVar6[-2],piVar6[-1]);
            if (puVar1 != (undefined4 *)0x0) {
              *piVar6 = piVar6[1];
              iVar4 = setting_on;
              if (piVar6[1] < 1) {
                *piVar6 = 0;
                if (iVar4 != 0) {
                  uVar2 = __ftol(piVar6[-0xb],piVar6[-10]);
                  uVar2 = __ftol(uVar2);
                  uVar2 = __ftol(uVar2);
                  play_door_sound(piVar6[10],piVar6[7],0x2b11,1000,uVar2);
                }
                piVar6[-3] = 0;
                generate_for_thing(piVar6[-4],piVar6[-2],piVar6[-1],0,*puVar1,puVar1[1],puVar1[2],
                                   puVar1[3],puVar1[4],puVar1[5],0xffffffff);
              }
              iVar4 = setting_on;
              if (0xfffe < *piVar6) {
                *piVar6 = 0xffff;
                if (iVar4 != 0) {
                  uVar2 = __ftol(piVar6[-0xb],piVar6[-10]);
                  uVar2 = __ftol(uVar2);
                  uVar2 = __ftol(uVar2);
                  play_door_sound(piVar6[10],piVar6[7],0x2b11,1000,uVar2);
                }
                piVar6[-3] = 0;
                piVar6[4] = piVar6[3];
                generate_for_thing(piVar6[-5],piVar6[-2],piVar6[-1],0,*puVar1,puVar1[1],puVar1[2],
                                   puVar1[3],puVar1[4],puVar1[5],0xffffffff);
              }
              update_door_position(iVar5);
              if (setting_on != 0) {
                if (piVar6[-3] == 0) {
                  init_door_and_lift_samples(iVar5 + 1000000);
                }
                else {
                  uVar2 = __ftol(piVar6[-0xb],piVar6[-10]);
                  uVar2 = __ftol(uVar2);
                  uVar2 = __ftol(uVar2);
                  set_door_sounds(piVar6[9],iVar5 + 1000000,piVar6[6],0x2b11,1000,uVar2);
                }
              }
            }
          }
        }
        else {
          piVar6[-3] = iVar4 + -10;
        }
      }
      iVar5 = iVar5 + 1;
      piVar6 = piVar6 + 0x2e;
    } while (iVar5 < num_doors);
  }
  return;
}



void script_door_or_lift_toggle(int param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  int local_c;
  
  iVar6 = 0;
  if (0 < num_doors) {
    piVar7 = &door_toggle_event;
    do {
      if ((*(byte *)(piVar7 + -1) & 0xf) != 0) {
        bVar2 = false;
        if (param_1 == *piVar7) {
          bVar2 = true;
          if ((piVar7[5] == 1) || (piVar7[8] == 0xffff)) {
            piVar7[5] = -1;
          }
          else {
            piVar7[5] = 1;
          }
        }
        else if (param_1 == piVar7[1]) {
          if (piVar7[8] < 0xffff) {
            bVar2 = true;
            piVar7[5] = 1;
          }
        }
        else if ((param_1 == piVar7[2]) && (0 < piVar7[8])) {
          piVar7[5] = -1;
          bVar2 = true;
        }
        iVar3 = setting_on;
        if (((bVar2) && (piVar7[0xc] = 0, iVar3 != 0)) &&
           (iVar3 = find_sector_3d(piVar7[6],piVar7[7]), iVar3 != 0)) {
          uVar4 = __ftol(piVar7[-3],piVar7[-2]);
          uVar4 = __ftol(uVar4);
          uVar4 = __ftol(uVar4);
          play_door_sound(piVar7[0x10],piVar7[0xd],0x2b11,1000,uVar4);
        }
      }
      iVar6 = iVar6 + 1;
      piVar7 = piVar7 + 0x2e;
    } while (iVar6 < num_doors);
  }
  local_c = 0;
  if (0 < num_lifts) {
    piVar7 = &lift_stop_event;
    do {
      if (piVar7[-0x1a] == 1) {
        bVar2 = false;
        if (param_1 == piVar7[-0xb]) {
          iVar6 = piVar7[-0xc];
          piVar7[-0xc] = iVar6 + 1;
          if (*piVar7 <= iVar6 + 1) {
            piVar7[-0xc] = 0;
          }
          bVar2 = true;
        }
        if ((param_1 == piVar7[-10]) && (piVar7[-0xc] < *piVar7 + -1)) {
          bVar2 = true;
          piVar7[-0xc] = piVar7[-0xc] + 1;
        }
        if ((param_1 == piVar7[-9]) && (0 < piVar7[-0xc])) {
          bVar2 = true;
          piVar7[-0xc] = piVar7[-0xc] + -1;
        }
        iVar6 = 0;
        if (0 < *piVar7) {
          piVar1 = piVar7 + 1;
          do {
            if (param_1 == *(int *)(&DAT_005a9130 + (iVar6 + *piVar1) * 4)) {
              if (*(int *)(&DAT_005a8e10 + (iVar6 + *piVar1) * 4) == piVar7[-0x10]) {
                piVar7[-0xd] = 0;
                piVar7[-0xc] = iVar6;
                puVar5 = (undefined4 *)engine_getobjectptr(piVar7[-0x1b]);
                if (puVar5 != (undefined4 *)0x0) {
                  generate_for_thing(*(undefined4 *)(&DAT_005a8af0 + (piVar7[-0xc] + *piVar1) * 4),0
                                     ,0,0,*puVar5,puVar5[1],puVar5[2],puVar5[3],puVar5[4],puVar5[5],
                                     0xffffffff);
                }
              }
              else if ((piVar7[-0xc] != iVar6) || (piVar7[-0xd] == 0)) {
                piVar7[-0xc] = iVar6;
                bVar2 = true;
              }
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < *piVar7);
        }
        if (bVar2) {
          piVar7[-0xe] = 0;
          if (piVar7[-0x10] < *(int *)(&DAT_005a8e10 + (piVar7[-0xc] + piVar7[1]) * 4)) {
            piVar7[-0xd] = 1;
          }
          else {
            piVar7[-0xd] = -1;
          }
          if ((setting_on != 0) && (iVar6 = engine_getobjectptr(piVar7[-0x1b]), iVar6 != 0)) {
            uVar4 = __ftol();
            uVar4 = __ftol(uVar4);
            uVar4 = __ftol(uVar4);
            play_sample_at_location(piVar7[-3],piVar7[-6],0x2b11,1000,uVar4);
          }
        }
      }
      local_c = local_c + 1;
      piVar7 = piVar7 + 0x2a;
    } while (local_c < num_lifts);
  }
  return;
}

void set_door_deltas(int param_1,int param_2,int param_3,int param_4,int param_5,double param_6,
                    double param_7,double param_8)

{
  double dVar1;
  double *pdVar2;
  int iVar3;
  
  if (0 < num_doors) {
    pdVar2 = (double *)&door_x_start;
    iVar3 = num_doors;
    do {
      if ((*(int *)((int)pdVar2 + 0x84) == param_1) && (*(int *)(pdVar2 + 0x11) == param_2)) {
        dVar1 = (double)*(int *)((int)pdVar2 + 0x8c) * 1.525902189669642e-05;
        *pdVar2 = (pdVar2[3] - *pdVar2) * dVar1 + *pdVar2;
        pdVar2[1] = (pdVar2[4] - pdVar2[1]) * dVar1 + pdVar2[1];
        pdVar2[2] = (pdVar2[5] - pdVar2[2]) * dVar1 + pdVar2[2];
        pdVar2[3] = (double)param_3 + *pdVar2;
        pdVar2[4] = (double)param_4 + pdVar2[1];
        pdVar2[5] = (double)param_5 + pdVar2[2];
        pdVar2[9] = param_6;
        pdVar2[10] = param_7;
        pdVar2[0xb] = param_8;
      }
      pdVar2 = pdVar2 + 0x17;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}



void set_door_position(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  if (0 < num_doors) {
    piVar1 = &door_object;
    iVar2 = num_doors;
    do {
      if ((piVar1[-1] == param_1) && (*piVar1 == param_2)) {
        piVar1[1] = param_3;
      }
      piVar1 = piVar1 + 0x2e;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}



void set_door_sounds(int obj_handle,int start_sample,int param_3,int param_4,int param_5,int param_6
                    ,int param_7,int param_8,undefined8 param_9)

{
  int *piVar1;
  int local_4;
  
  if (0 < num_doors) {
    local_4 = num_doors;
    piVar1 = &door_object;
    do {
      if ((piVar1[-1] == obj_handle) && (*piVar1 == start_sample)) {
        piVar1[9] = param_3;
        piVar1[10] = param_5;
        piVar1[0xb] = param_7;
        piVar1[6] = param_4;
        piVar1[7] = param_6;
        piVar1[8] = param_8;
        *(undefined8 *)(piVar1 + -10) = param_9;
      }
      piVar1 = piVar1 + 0x2e;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  return;
}



void set_door_speed(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  if (0 < num_doors) {
    piVar1 = &door_object;
    iVar2 = num_doors;
    do {
      if ((piVar1[-1] == param_1) && (*piVar1 == param_2)) {
        piVar1[3] = param_3;
      }
      piVar1 = piVar1 + 0x2e;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}



void update_lift_positions(int param_1)

{
  double *pdVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  
  iVar4 = 0;
  if (0 < num_lifts) {
    piVar5 = &lift_mode;
    do {
      if (piVar5[-0xd] == 1) {
        if (*piVar5 == 0) {
          iVar2 = piVar5[-0xe];
          dVar8 = 0.0;
          dVar7 = 0.0;
          dVar6 = 0.0;
        }
        else {
          pdVar1 = (double *)engine_getobjectptr();
          if (pdVar1 == (double *)0x0) goto LAB_0045027d;
          iVar2 = param_1 * piVar5[-5] * *piVar5 + piVar5[-3];
          piVar5[-2] = iVar2;
          if (((*piVar5 < 0) &&
              (iVar3 = *(int *)(&DAT_005a8e10 + (piVar5[0xe] + piVar5[1]) * 4), iVar2 <= iVar3)) ||
             ((0 < *piVar5 &&
              (iVar3 = *(int *)(&DAT_005a8e10 + (piVar5[0xe] + piVar5[1]) * 4), iVar3 <= iVar2)))) {
            piVar5[-2] = iVar3;
          }
          dVar6 = (double)piVar5[-2] * 1.525902189669642e-05;
          dVar8 = ((double)piVar5[-9] + (double)piVar5[-6] * dVar6) - pdVar1[2];
          dVar7 = ((double)piVar5[-10] + (double)piVar5[-7] * dVar6) - pdVar1[1];
          iVar2 = piVar5[-0xe];
          dVar6 = ((double)piVar5[-0xb] + (double)piVar5[-8] * dVar6) - *pdVar1;
        }
        engine_setobjectmvector(iVar2,dVar6,dVar7,dVar8);
      }
LAB_0045027d:
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 0x2a;
    } while (iVar4 < num_lifts);
  }
  return;
}



void synch_lifts(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = 0;
  if (0 < num_lifts) {
    piVar5 = &DAT_00836e40;
    do {
      if (piVar5[-0xb] == 1) {
        iVar3 = piVar5[2];
        if (iVar3 < -9) {
          piVar5[2] = iVar3 + 10;
        }
        else if (iVar3 < 10) {
          if (iVar3 == 0) {
            if (((0 < piVar5[1]) && (iVar3 = piVar5[1] - param_1, piVar5[1] = iVar3, iVar3 < 1)) &&
               (piVar5[1] = 0, piVar5[-1] != *(int *)(&DAT_005a8e10 + piVar5[0x10] * 4))) {
              iVar3 = piVar5[3];
              piVar5[3] = iVar3 + 1;
              if (piVar5[0xf] <= iVar3 + 1) {
                piVar5[3] = 0;
              }
              piVar5[2] = ((*(int *)(&DAT_005a8e10 + (piVar5[3] + piVar5[0x10]) * 4) <= piVar5[-1])
                           - 1 & 2) - 1;
              if ((setting_on != 0) && (iVar3 = engine_getobjectptr(piVar5[-0xc]), iVar3 != 0)) {
                uVar2 = __ftol();
                uVar2 = __ftol(uVar2);
                uVar2 = __ftol(uVar2);
                play_sample_at_location(piVar5[0xc],piVar5[9],0x2b11,1000,uVar2);
              }
            }
          }
          else {
            puVar1 = (undefined4 *)engine_getobjectptr(piVar5[-0xc]);
            if (puVar1 != (undefined4 *)0x0) {
              iVar3 = *piVar5;
              piVar5[-1] = iVar3;
              if (((piVar5[2] < 0) &&
                  (iVar3 <= *(int *)(&DAT_005a8e10 + (piVar5[3] + piVar5[0x10]) * 4))) ||
                 ((0 < piVar5[2] &&
                  (*(int *)(&DAT_005a8e10 + (piVar5[3] + piVar5[0x10]) * 4) <= iVar3)))) {
                piVar5[2] = 0;
                piVar5[-1] = *(int *)(&DAT_005a8e10 + (piVar5[3] + piVar5[0x10]) * 4);
                if (setting_on != 0) {
                  uVar2 = __ftol();
                  uVar2 = __ftol(uVar2);
                  uVar2 = __ftol(uVar2);
                  play_sample_at_location(piVar5[0xe],piVar5[0xb],0x2b11,1000,uVar2);
                }
                generate_for_thing(*(undefined4 *)(&DAT_005a8af0 + (piVar5[3] + piVar5[0x10]) * 4),0
                                   ,0,0,*puVar1,puVar1[1],puVar1[2],puVar1[3],puVar1[4],puVar1[5],
                                   0xffffffff);
                piVar5[1] = piVar5[-2];
              }
              lift_update_position(iVar4);
              if (setting_on != 0) {
                if (piVar5[2] == 0) {
                  init_door_and_lift_samples(iVar4 + 2000000);
                }
                else {
                  uVar2 = __ftol();
                  uVar2 = __ftol(uVar2);
                  uVar2 = __ftol(uVar2);
                  play_frame_loop(piVar5[0xd],iVar4 + 2000000,piVar5[10],0x2b11,1000,uVar2);
                }
              }
            }
          }
        }
        else {
          piVar5[2] = iVar3 + -10;
        }
      }
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 0x2a;
    } while (iVar4 < num_lifts);
  }
  return;
}



int find_lift(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < num_lifts) {
    piVar2 = &DAT_00836e10;
    do {
      if ((piVar2[1] != 0) && (*piVar2 == param_1)) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0x2a;
    } while (iVar1 < num_lifts);
  }
  return -1;
}



int check_door_sector(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < num_doors) {
    piVar2 = &door_sector;
    do {
      if ((((*(byte *)(piVar2 + -7) & 0xf) != 0) && (*piVar2 == param_1)) && (piVar2[1] == param_2))
      {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0x2e;
    } while (iVar1 < num_doors);
  }
  return -1;
}



void generate_door_or_lift_event(int param_1)

{
  double dVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = check_door_sector();
    if (-1 < iVar2) {
      if ((*(uint *)(&door_type + iVar2 * 0xb8) & 0xf) == 2) {
        if ((&DAT_00838230)[iVar2 * 0x2e] != (&door_position)[iVar2 * 0x2e]) {
          (&door_mode)[iVar2 * 0x2e] = 1;
          (&DAT_00838230)[iVar2 * 0x2e] = (&door_position)[iVar2 * 0x2e];
          return;
        }
      }
      else if (((*(uint *)(&door_type + iVar2 * 0xb8) & 0xf) == 3) &&
              ((&DAT_00838230)[iVar2 * 0x2e] != (&door_position)[iVar2 * 0x2e])) {
        (&DAT_00838230)[iVar2 * 0x2e] = (&door_position)[iVar2 * 0x2e];
        if ((-1 < DAT_004aa380) && (DAT_004aa380 < 0x10c)) {
          dVar1 = (double)(&door_position)[iVar2 * 0x2e] * 1.525902189669642e-05;
          generate_for_thing(0xffffffea,(&door_sector)[iVar2 * 0x2e],(&door_object)[iVar2 * 0x2e],0,
                             ((double)(&door_x_end)[iVar2 * 0x17] -
                             (double)(&door_x_start)[iVar2 * 0x17]) * dVar1 +
                             (double)(&door_x_start)[iVar2 * 0x17],
                             ((double)(&door_y_end)[iVar2 * 0x17] -
                             (double)(&door_y_start)[iVar2 * 0x17]) * dVar1 +
                             (double)(&door_y_start)[iVar2 * 0x17],
                             ((double)(&door_z_end)[iVar2 * 0x17] -
                             (double)(&door_z_start)[iVar2 * 0x17]) * dVar1 +
                             (double)(&door_z_start)[iVar2 * 0x17],DAT_004aa380 + -0x10000);
        }
      }
    }
  }
  else {
    iVar2 = find_lift(param_1);
    if (-1 < iVar2) {
      if ((&DAT_00836e40)[iVar2 * 0x2a] != (&lift_position)[iVar2 * 0x2a]) {
        (&DAT_00836e40)[iVar2 * 0x2a] = (&lift_position)[iVar2 * 0x2a];
        if ((-1 < DAT_004aa380) && (DAT_004aa380 < 0x10c)) {
          dVar1 = (double)(&lift_position)[iVar2 * 0x2a] * 1.525902189669642e-05;
          generate_for_thing(0xffffffea,0xffffffff,0,0,
                             (double)(&lift_x)[iVar2 * 0x2a] +
                             (double)(&lift_delta_x)[iVar2 * 0x2a] * dVar1,
                             (double)(&lift_y)[iVar2 * 0x2a] +
                             (double)(&lift_delta_y)[iVar2 * 0x2a] * dVar1,
                             (double)(&lift_z)[iVar2 * 0x2a] +
                             (double)(&lift_delta_z)[iVar2 * 0x2a] * dVar1,DAT_004aa380 + -0x10000);
          return;
        }
      }
    }
  }
  return;
}
