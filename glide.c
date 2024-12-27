uint glidelibinit(void)

{
  HMODULE hModule;
  int iVar1;
  
  hModule = LoadLibraryA(s_glide2x_dll_004a61b8);
  if (hModule == (HMODULE)0x0) {
    log_message(s_Unable_to_load_library__glide2x__004a6358);
    return 0xffffffff;
  }
  grGlideInit = GetProcAddress(hModule,s__grGlideInit_0_004a6348);
  if (grGlideInit == (FARPROC)0x0) {
    return 0xfffffffe;
  }
  grSstIdle = GetProcAddress(hModule,s__grSstIdle_0_004a6338);
  if (grSstIdle == (FARPROC)0x0) {
    return 0xfffffffe;
  }
  grGlideShutdown = GetProcAddress(hModule,s__grGlideShutdown_0_004a6324);
  if (grGlideShutdown == (FARPROC)0x0) {
    return 0xfffffffd;
  }
  grBufferNumPending = GetProcAddress(hModule,s__grBufferNumPending_0_004a630c);
  if (grBufferNumPending == (FARPROC)0x0) {
    return 0xfffffffd;
  }
  _grSstControl = GetProcAddress(hModule,s__grSstControl_4_004a62fc);
  if (_grSstControl == (FARPROC)0x0) {
    return 0xfffffffd;
  }
  grSstQueryHardware = GetProcAddress(hModule,s__grSstQueryHardware_4_004a62e4);
  if (grSstQueryHardware == (FARPROC)0x0) {
    return 0xfffffffc;
  }
  grSstSelect = GetProcAddress(hModule,s__grSstSelect_4_004a62d4);
  if (grSstSelect == (FARPROC)0x0) {
    return 0xfffffffb;
  }
  _grGlideShamelessPlug = GetProcAddress(hModule,s__grGlideShamelessPlug_4_004a62bc);
  if (_grGlideShamelessPlug == (FARPROC)0x0) {
    return 0xfffffffa;
  }
  grSstWinOpen = GetProcAddress(hModule,s__grSstWinOpen_28_004a62a8);
  if (grSstWinOpen == (FARPROC)0x0) {
    return 0xfffffff9;
  }
  grBufferSwap = GetProcAddress(hModule,s__grBufferSwap_4_004a6298);
  if (grBufferSwap == (FARPROC)0x0) {
    return 0xfffffff8;
  }
  grLfbLock = GetProcAddress(hModule,s__grLfbLock_24_004a6288);
  if (grLfbLock == (FARPROC)0x0) {
    return 0xfffffff7;
  }
  grLfbUnlock = GetProcAddress(hModule,s__grLfbUnlock_8_004a6278);
  if (grLfbUnlock == (FARPROC)0x0) {
    return 0xfffffff6;
  }
  grSstWinClose = GetProcAddress(hModule,s__grSstWinClose_0_004a6264);
  if (grSstWinClose == (FARPROC)0x0) {
    return 0xfffffff5;
  }
  iVar1 = load_glide_functions(hModule);
  return (uint)(iVar1 != 0);
}



undefined4 win_check_glide_2x(char *param_1)

{
  char cVar1;
  int iVar2;
  UINT UVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  char *pcVar9;
  char *pcVar10;
  undefined4 *puVar11;
  CHAR local_200;
  undefined4 local_1ff [127];
  
  iVar2 = read_glide_2x_dll(param_1);
  if (iVar2 != 0) {
    return 0;
  }
  UVar3 = GetSystemDirectoryA(&local_200,0x1e0);
  if ((0 < (int)UVar3) && ((int)UVar3 < 0x1e1)) {
    (&local_200)[UVar3] = '\\';
    uVar5 = 0xffffffff;
    pcVar4 = param_1;
    do {
      pcVar9 = pcVar4;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar9 = pcVar4 + 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar9;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    puVar8 = (undefined4 *)(pcVar9 + -uVar5);
    puVar11 = (undefined4 *)(&local_200 + UVar3 + 1);
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar11 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar11 = puVar11 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined *)puVar11 = *(undefined *)puVar8;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      puVar11 = (undefined4 *)((int)puVar11 + 1);
    }
    iVar2 = read_glide_2x_dll(&local_200);
    if (iVar2 != 0) {
      return 0;
    }
  }
  UVar3 = GetWindowsDirectoryA(&local_200,0x1e0);
  if ((0 < (int)UVar3) && ((int)UVar3 < 0x1e1)) {
    (&local_200)[UVar3] = '\\';
    uVar5 = 0xffffffff;
    pcVar4 = param_1;
    do {
      pcVar9 = pcVar4;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar9 = pcVar4 + 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar9;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    puVar8 = (undefined4 *)(pcVar9 + -uVar5);
    puVar11 = (undefined4 *)(&local_200 + UVar3 + 1);
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar11 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar11 = puVar11 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined *)puVar11 = *(undefined *)puVar8;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      puVar11 = (undefined4 *)((int)puVar11 + 1);
    }
    iVar2 = read_glide_2x_dll(&local_200);
    if (iVar2 != 0) {
      return 0;
    }
  }
  pcVar4 = (char *)_getenv(s_PATH_004a6380);
  if ((pcVar4 == (char *)0x0) || (iVar2 = 0, *pcVar4 == '\0')) {
    return 0xffffffff;
  }
  do {
    for (; (cVar1 = pcVar4[iVar2], cVar1 == ' ' || ((cVar1 == '\t' || (cVar1 == ';'))));
        iVar2 = iVar2 + 1) {
    }
    cVar1 = pcVar4[iVar2];
    for (iVar7 = 0;
        (((cVar1 != ' ' && (cVar1 != ';')) && (cVar1 != '\t')) &&
        (((cVar1 != '\0' && (cVar1 != '\n')) && ((cVar1 != '\r' && (iVar7 < 0x100))))));
        iVar7 = iVar7 + 1) {
      (&local_200)[iVar7] = cVar1;
      cVar1 = pcVar4[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    if (2 < iVar7) {
      (&local_200)[iVar7] = '\\';
      uVar5 = 0xffffffff;
      pcVar9 = param_1;
      do {
        pcVar10 = pcVar9;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar10 = pcVar9 + 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar10;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      puVar8 = (undefined4 *)(pcVar10 + -uVar5);
      puVar11 = (undefined4 *)(&local_200 + iVar7 + 1);
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar11 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar11 = puVar11 + 1;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined *)puVar11 = *(undefined *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      }
      iVar7 = read_glide_2x_dll(&local_200);
      if (iVar7 != 0) {
        return 0;
      }
    }
    if (pcVar4[iVar2] == '\0') {
      return 0xffffffff;
    }
  } while( true );
}



undefined4 read_glide_2x_dll(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _fopen(param_1,s_rb_004a6388);
  if (iVar1 != 0) {
    _fclose(iVar1);
    return 1;
  }
  return 0;
}
