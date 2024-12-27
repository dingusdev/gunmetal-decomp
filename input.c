char * init_direct_input(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piStack_38;
  undefined *puStack_34;
  int *piStack_30;
  undefined *puStack_2c;
  undefined4 *puStack_28;
  undefined4 uStack_24;
  
  DAT_004bf2a0 = param_2;
  iVar1 = 0;
  do {
    (&keyboard_extended)[iVar1] = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x80);
  uStack_24 = 0;
  puStack_28 = &input_device;
  puStack_2c = (undefined *)0x500;
  piStack_30 = (int *)param_1;
  DAT_004bf4a8 = 0;
  DAT_004bfce4 = 0;
  DAT_004bfce8 = 0;
  DAT_004bfcec = 0;
  puStack_34 = (undefined *)0x404b4f;
  iVar1 = DirectInputCreateA();
  if (iVar1 < 0) {
    return s_Direct_Input_Create_failed_004a5f54;
  }
  uStack_24 = 0;
  puStack_28 = &keyboard_state;
  puStack_2c = &DAT_004a14a8;
  piStack_30 = input_device;
  puStack_34 = (undefined *)0x404b75;
  iVar1 = (**(code **)(*input_device + 0xc))();
  if (iVar1 < 0) {
    return s_Create_Keyboard_Device_failed_004a5f34;
  }
  puStack_34 = &DAT_00408fd0;
  piStack_38 = keyboard_state;
  iVar1 = (**(code **)(*keyboard_state + 0x2c))();
  if (iVar1 < 0) {
    return s_Set_Keyboard_Data_Format_failed_004a5f14;
  }
  iVar1 = (**(code **)(*keyboard_state + 0x34))(keyboard_state,param_2,6);
  if (iVar1 < 0) {
    return s_Set_Keyboard_Cooperative_Level_F_004a5eec;
  }
  piStack_38 = (int *)0x14;
  puStack_34 = (undefined *)0x10;
  piStack_30 = (int *)0x0;
  puStack_2c = (undefined *)0x0;
  puStack_28 = (undefined4 *)0x20;
  iVar1 = (**(code **)(*keyboard_state + 0x18))(keyboard_state,1,&piStack_38);
  if (iVar1 < 0) {
    return s_Set_Keyboard_Buffer_Size_Failed_004a5ecc;
  }
  if (_mouse_status == 0) {
    iVar1 = (**(code **)(*input_device + 0xc))(input_device,&DAT_004a1498,&mouse_device,0);
    if (iVar1 < 0) {
      return s_Mouse_Create_Device_Failed_004a5eb0;
    }
    iVar1 = (**(code **)(*mouse_device + 0x2c))(mouse_device,&LAB_00407fb0);
    if (iVar1 < 0) {
      return s_Mouse_Set_Data_Format_Failed_004a5e90;
    }
    iVar1 = (**(code **)(*mouse_device + 0x34))(mouse_device,param_2,5);
    if (iVar1 < 0) {
      return s_Mouse_Set_Cooperation_Level_Fail_004a5e6c;
    }
    enable_mouse = 1;
  }
  puVar3 = &DAT_004bf328;
  for (iVar1 = 0x60; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  DAT_004bf630 = 0xd2f1a9fc;
  _DAT_004bf634 = 0x3f50624d;
  puVar3 = &DAT_004bf630;
  puVar2 = &DAT_004bf638;
  for (iVar1 = 0x5e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_004bf7e4;
  puVar3 = &DAT_004bf4b0;
  for (iVar1 = 0x60; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  do {
    puVar2[-1] = 0;
    *puVar2 = 0;
    puVar2 = puVar2 + 0x1f;
  } while ((int)puVar2 < 0x4bfbc4);
  if (_joystick_status == 0) {
    (**(code **)(*input_device + 0x10))(input_device,4,&LAB_00404d00,0,1);
  }
  return (char *)0x0;
}



void win_initialize_input(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  bool bVar6;
  uint local_314;
  short asStack_310 [2];
  short sStack_30c;
  short sStack_308;
  byte abStack_304 [4];
  char acStack_300 [256];
  undefined4 local_200;
  byte abStack_1fc [508];
  
  if (keyboard_state != (int *)0x0) {
    local_314 = 0x20;
    iVar1 = (**(code **)(*keyboard_state + 0x28))(keyboard_state,0x10,&local_200,&local_314,0);
    if (iVar1 != 0) {
      do {
        iVar2 = (**(code **)(*keyboard_state + 0x24))(keyboard_state,0x100,acStack_300);
        if (iVar2 == 0) {
          log_message(s_GetDeviceState_Keyboard_OK__004a5f70);
          iVar2 = 0;
          do {
            iVar3 = win_remap_keyboard(iVar2);
            DAT_004bf4a8 = iVar3;
            if (acStack_300[iVar2] == '\0') {
              if ((&keyboard_extended)[iVar3] != '\0') {
                (&keyboard_extended)[iVar3] = 0;
                win_keyboard_logic(iVar3);
              }
            }
            else if ((&keyboard_extended)[iVar3] == '\0') {
              (&keyboard_extended)[iVar3] = 1;
              win_keyboard_extended_logic(iVar3);
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < 0x100);
        }
        if ((iVar1 != -0x7ff8ffe2) && (iVar1 != -0x7ff8fff4)) break;
        iVar1 = (**(code **)(*keyboard_state + 0x1c))(keyboard_state);
        if (iVar1 < 0) goto LAB_0040565b;
        local_314 = 0x20;
        iVar1 = (**(code **)(*keyboard_state + 0x28))(keyboard_state,0x10,&local_200,&local_314,0);
      } while (iVar1 != 0);
      if (iVar1 < 0) goto LAB_0040565b;
    }
    if ((local_314 != 0) && (uVar5 = 0, local_314 != 0)) {
      pbVar4 = abStack_1fc;
      do {
        iVar1 = win_remap_keyboard(*(undefined4 *)(pbVar4 + -4));
        DAT_004bf4a8 = iVar1;
        if ((*pbVar4 & 0x80) == 0) {
          (&keyboard_extended)[iVar1] = 0;
          win_keyboard_logic(iVar1);
        }
        else {
          bVar6 = DAT_004bfce4 != 0;
          (&keyboard_extended)[iVar1] = 1;
          if (bVar6) {
            if (DAT_004bf4a8 < 0x7b) {
              (&DAT_004bfb90)[DAT_004bfce8] = (&DAT_004a5b08)[DAT_004bf4a8];
            }
            else {
              (&DAT_004bfb90)[DAT_004bfce8] = 0xff;
            }
            DAT_004bfce8 = DAT_004bfce8 + 1;
            if (0xff < DAT_004bfce8) {
              DAT_004bfce8 = 0;
            }
            if ((DAT_004bfce8 == DAT_004bfcec) &&
               (DAT_004bfce8 = DAT_004bfce8 + -1, DAT_004bfce8 < 0)) {
              DAT_004bfce8 = 0xff;
            }
          }
          win_keyboard_extended_logic(DAT_004bf4a8);
        }
        uVar5 = uVar5 + 1;
        pbVar4 = pbVar4 + 0x10;
      } while (uVar5 < local_314);
    }
  }
LAB_0040565b:
  if (mouse_device != (int *)0x0) {
    mouse_event_bits = 0;
    do {
      iVar1 = (**(code **)(*mouse_device + 0x24))(mouse_device,0x10,asStack_310);
      if ((iVar1 != -0x7ff8ffe2) && (iVar1 != -0x7ff8fff4)) break;
      iVar1 = 0;
      do {
        if ((&DAT_004bfce0)[iVar1] != '\0') {
          (&DAT_004bfce0)[iVar1] = 0;
          mouse_event_bits = mouse_event_bits | 4 << ((char)iVar1 * '\x02' & 0x1fU);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < 4);
      iVar1 = (**(code **)(*mouse_device + 0x1c))(mouse_device);
    } while (-1 < iVar1);
    if (-1 < iVar1) {
      mouse_event_bits = 0;
      iVar1 = 0;
      do {
        if ((abStack_304[iVar1] & 0x80) == 0) {
          if ((&DAT_004bfce0)[iVar1] != '\0') {
            (&DAT_004bfce0)[iVar1] = 0;
            mouse_event_bits = mouse_event_bits | 4 << ((char)iVar1 * '\x02' & 0x1fU);
          }
        }
        else if ((&DAT_004bfce0)[iVar1] == '\0') {
          (&DAT_004bfce0)[iVar1] = 1;
          mouse_event_bits = mouse_event_bits | 2 << ((char)iVar1 * '\x02' & 0x1fU);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < 4);
      mouse_raw_x = mouse_raw_x + asStack_310[0];
      mouse_raw_y = mouse_raw_y + sStack_30c;
      mouse_raw_z = mouse_raw_z + sStack_308;
      win_mouse_logic();
      return;
    }
    if (mouse_event_bits != 0) {
      win_mouse_logic();
    }
  }
  return;
}



undefined4 win_remap_keyboard(undefined4 param_1)

{
  switch(param_1) {
  case 0x57:
    return 0x54;
  case 0x58:
    return 0x55;
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
  case 0x60:
  case 0x61:
  case 0x62:
  case 99:
  case 0x67:
  case 0x68:
  case 0x69:
  case 0x6a:
  case 0x6b:
  case 0x6c:
  case 0x6d:
  case 0x6e:
  case 0x6f:
  case 0x71:
  case 0x72:
  case 0x73:
  case 0x74:
  case 0x75:
  case 0x76:
  case 0x77:
  case 0x78:
  case 0x7a:
  case 0x7c:
  case 0x7e:
  case 0x7f:
  case 0x80:
  case 0x81:
  case 0x82:
  case 0x83:
  case 0x84:
  case 0x85:
  case 0x86:
  case 0x87:
  case 0x88:
  case 0x89:
  case 0x8a:
  case 0x8b:
  case 0x8c:
  case 0x8e:
  case 0x8f:
  case 0x98:
  case 0x99:
  case 0x9a:
  case 0x9b:
  case 0x9e:
  case 0x9f:
  case 0xa0:
  case 0xa1:
  case 0xa2:
  case 0xa3:
  case 0xa4:
  case 0xa5:
  case 0xa6:
  case 0xa7:
  case 0xa8:
  case 0xa9:
  case 0xaa:
  case 0xab:
  case 0xac:
  case 0xad:
  case 0xae:
  case 0xaf:
  case 0xb0:
  case 0xb1:
  case 0xb2:
  case 0xb4:
  case 0xb6:
  case 0xb9:
  case 0xba:
  case 0xbb:
  case 0xbc:
  case 0xbd:
  case 0xbe:
  case 0xbf:
  case 0xc0:
  case 0xc1:
  case 0xc2:
  case 0xc3:
  case 0xc4:
  case 0xc5:
  case 0xc6:
  case 0xca:
  case 0xcc:
  case 0xce:
  case 0xd4:
  case 0xd5:
  case 0xd6:
  case 0xd7:
  case 0xd8:
  case 0xd9:
  case 0xda:
    param_1 = 0;
    break;
  case 100:
    return 0x56;
  case 0x65:
    return 0x57;
  case 0x66:
    return 0x58;
  case 0x70:
    return 0x59;
  case 0x79:
    return 0x5a;
  case 0x7b:
    return 0x5b;
  case 0x7d:
    return 0x5c;
  case 0x8d:
    return 0x5d;
  case 0x90:
    return 0x5e;
  case 0x91:
    return 0x5f;
  case 0x92:
    return 0x60;
  case 0x93:
    return 0x61;
  case 0x94:
    return 0x62;
  case 0x95:
    return 99;
  case 0x96:
    return 100;
  case 0x97:
    return 0x65;
  case 0x9c:
    return 0x66;
  case 0x9d:
    return 0x67;
  case 0xb3:
    return 0x68;
  case 0xb5:
    return 0x69;
  case 0xb7:
    return 0x6a;
  case 0xb8:
    return 0x6b;
  case 199:
    return 0x6c;
  case 200:
    return 0x6d;
  case 0xc9:
    return 0x6e;
  case 0xcb:
    return 0x6f;
  case 0xcd:
    return 0x70;
  case 0xcf:
    return 0x71;
  case 0xd0:
    return 0x72;
  case 0xd1:
    return 0x73;
  case 0xd2:
    return 0x74;
  case 0xd3:
    return 0x75;
  case 0xdb:
    return 0x76;
  case 0xdc:
    return 0x77;
  case 0xdd:
    return 0x78;
  }
  return param_1;
}



void track_input(undefined4 param_1,int param_2)

{
  int *piVar1;
  int **ppiVar2;
  
  if (param_2 != 0) {
    if (keyboard_state != (int *)0x0) {
      (**(code **)(*keyboard_state + 0x20))(keyboard_state);
    }
    if (mouse_device != (int *)0x0) {
      (**(code **)(*mouse_device + 0x20))(mouse_device);
    }
    ppiVar2 = (int **)&DAT_004bfca8;
    do {
      piVar1 = *ppiVar2;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x20))(piVar1);
      }
      ppiVar2 = ppiVar2 + 1;
    } while ((int)ppiVar2 < 0x4bfcc8);
    return;
  }
  if (keyboard_state != (int *)0x0) {
    (**(code **)(*keyboard_state + 0x1c))(keyboard_state);
  }
  if (mouse_device != (int *)0x0) {
    (**(code **)(*mouse_device + 0x1c))(mouse_device);
  }
  ppiVar2 = (int **)&DAT_004bfca8;
  do {
    piVar1 = *ppiVar2;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x1c))(piVar1);
    }
    ppiVar2 = ppiVar2 + 1;
  } while ((int)ppiVar2 < 0x4bfcc8);
  return;
}



undefined4 reset_input_devices(void)

{
  int *piVar1;
  int **ppiVar2;
  undefined4 *puVar3;
  
  if (keyboard_state != (int *)0x0) {
    (**(code **)(*keyboard_state + 0x20))(keyboard_state);
    (**(code **)(*keyboard_state + 8))(keyboard_state);
    keyboard_state = (int *)0x0;
  }
  if (mouse_device != (int *)0x0) {
    (**(code **)(*mouse_device + 0x20))(mouse_device);
    (**(code **)(*mouse_device + 8))(mouse_device);
    mouse_device = (int *)0x0;
    enable_mouse = 0;
  }
  puVar3 = (undefined4 *)&DAT_004bf7e0;
  ppiVar2 = (int **)&DAT_004bfca8;
  do {
    piVar1 = *ppiVar2;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x20))(piVar1);
      (**(code **)(**ppiVar2 + 8))(*ppiVar2);
      *ppiVar2 = (int *)0x0;
      *puVar3 = 0;
    }
    ppiVar2 = ppiVar2 + 1;
    puVar3 = puVar3 + 0x1f;
  } while ((int)ppiVar2 < 0x4bfcc8);
  if (input_device != (int *)0x0) {
    (**(code **)(*input_device + 8))(input_device);
    input_device = (int *)0x0;
  }
  return 0;
}
