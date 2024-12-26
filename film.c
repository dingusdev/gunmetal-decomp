int open_fdx(char *param_1,int param_2,undefined4 param_3,int *param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  int local_24;
  undefined local_20 [32];
  
  uVar4 = 0xffffffff;
  pcVar5 = param_1;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  local_24 = -1;
  if (0x14 < ~uVar4 - 1) {
    log_message(s_FILM_name_too_long__s_004beaf0,param_1);
    return -1;
  }
  _sprintf(local_20,s_FILM__s_fdx_004beae4,param_1);
  iVar2 = _fopen(local_20,s_r_004a6888);
  if (iVar2 == 0) {
    log_message(s_couldn_t_open_FILM__s_d_fdx_004bea84,param_1,param_2);
  }
  else {
    if (0 < param_2) {
      do {
        param_2 = param_2 + -1;
        if ((*(byte *)(iVar2 + 0xc) & 0x10) != 0) goto LAB_00498ebb;
        do {
          iVar3 = read_from_file_buf(iVar2);
          if (iVar3 == 10) break;
        } while ((*(byte *)(iVar2 + 0xc) & 0x10) == 0);
      } while (0 < param_2);
    }
    if ((*(byte *)(iVar2 + 0xc) & 0x10) == 0) {
      iVar3 = get_count(iVar2,s__ld__ld_004beac0,param_3,param_4);
      if (iVar3 != -1) {
        local_24 = 0;
        _fclose(iVar2);
        goto LAB_00498f1f;
      }
      pcVar5 = s_index_wrong_FILM__s_fdx_004beaa4;
    }
    else {
LAB_00498ebb:
      pcVar5 = s_couldn_t_index_FILM__s_fdx_004beac8;
    }
    log_message(pcVar5,param_1);
    _fclose(iVar2);
  }
LAB_00498f1f:
  if ((local_24 == 0) && (*param_4 < 1)) {
    log_message(s_invalid_FPS_for_film__s_004bea68,param_1);
    local_24 = -1;
  }
  return local_24;
}
