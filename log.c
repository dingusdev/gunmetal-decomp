undefined4 prune_log(LPCSTR param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  
  BVar1 = DeleteFileA(param_1);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
  }
  else {
    DVar2 = 0;
  }
  if (DVar2 != 0) {
    __dosmaperr(DVar2);
    return 0xffffffff;
  }
  return 0;
}

void set_log_name(char *param_1)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 *puVar6;
  
  if (param_1 != (char *)0x0) {
    uVar2 = 0xffffffff;
    do {
      pcVar5 = param_1;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar5 = param_1 + 1;
      cVar1 = *param_1;
      param_1 = pcVar5;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    puVar4 = (undefined4 *)(pcVar5 + -uVar2);
    puVar6 = (undefined4 *)s_LOG_LOG_004a69d8;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined *)puVar6 = *(undefined *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
  }
  prune_log(s_LOG_LOG_004a69d8);
  return;
}


void log_message(char *param_1)
{
  FILE *_File;
  
  _File = (FILE *)_fopen(s_LOG_LOG_004a69d8,s_at_004a6a34);
  if (_File != (FILE *)0x0) {
    if (DAT_004a6a28 != -1) {
      __fwprintf(_File,(wchar_t *)s__ld__004a6a2c,DAT_004a6a28);
    }
    _vfprintf(_File,param_1,&stack0x00000008);
    _fclose(_File);
  }
  return;
}
