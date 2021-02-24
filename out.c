
/* WARNING: Control flow encountered bad instruction data */

void exit@@GLIBC_2.2.5(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* WARNING: Control flow encountered bad instruction data */

void __printf_chk@@GLIBC_2.3.4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* WARNING: Control flow encountered bad instruction data */

void strcmp@@GLIBC_2.2.5(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* WARNING: Control flow encountered bad instruction data */

void __libc_start_main@@GLIBC_2.2.5(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* WARNING: Control flow encountered bad instruction data */

void puts@@GLIBC_2.2.5(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

void _init(void)

{
  if (pcRam0000000000403ff8 != exit@@GLIBC_2.2.5) {
    (*pcRam0000000000403ff8)();
  }
  return;
}

xunknown8 main(int4 param_1,int8 param_2)

{
  uint1 *puVar1;
  int4 iVar2;
  int8 iVar3;
  xunknown8 extraout_RDX;
  xunknown8 unaff_RBP;
  uint1 *puVar4;
  uint1 *puVar5;
  xunknown1 xVar6;
  bool bVar7;
  xunknown1 xVar8;
  bool bVar9;
  uint1 uVar10;
  
  uVar10 = 0;
  if (1 < param_1) {
    puVar1 = *(uint1 **)(param_2 + 8);
    xVar6 = 0;
    xVar8 = 1;
    func_0x00401050(1,0x402048,puVar1);
    iVar3 = 6;
    puVar4 = puVar1;
    puVar5 = (uint1 *)0x402054;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      xVar6 = *puVar4 < *puVar5;
      xVar8 = *puVar4 == *puVar5;
      puVar4 = puVar4 + (uint8)uVar10 * -2 + 1;
      puVar5 = puVar5 + (uint8)uVar10 * -2 + 1;
    } while ((bool)xVar8);
    bVar7 = false;
    bVar9 = (!(bool)xVar6 && !(bool)xVar8) == (bool)xVar6;
    if (bVar9) {
      test1();
    }
    else {
      iVar3 = 6;
      puVar4 = puVar1;
      puVar5 = (uint1 *)0x40205a;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *puVar4 < *puVar5;
        bVar9 = *puVar4 == *puVar5;
        puVar4 = puVar4 + (uint8)uVar10 * -2 + 1;
        puVar5 = puVar5 + (uint8)uVar10 * -2 + 1;
      } while (bVar9);
      if ((!bVar7 && !bVar9) == bVar7) {
        test2();
      }
      else {
        iVar2 = func_0x00401040(puVar1,0x402060);
        if (iVar2 == 0) {
          test3();
        }
        else {
          iVar2 = func_0x00401040(puVar1,0x402066);
          if (iVar2 == 0) {
            test4();
          }
          else {
            iVar2 = func_0x00401040(puVar1,0x40206c);
            if (iVar2 == 0) {
              test5();
            }
            else {
              iVar2 = func_0x00401040(puVar1,0x402072);
              if (iVar2 != 0) goto code_r0x00401156;
              test6();
            }
          }
        }
      }
    }
    return 0;
  }
  func_0x00401030(0x402090);
  func_0x00401060(1);
code_r0x00401156:
  func_0x00401050(1,0x402078);
  func_0x00401060(1);
  (*pcRam0000000000403ff0)
            (main,unaff_RBP,register0x00000020,__libc_csu_init,__libc_csu_fini,extraout_RDX,
             &stack0xfffffffffffffff8);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

void _start(xunknown8 param_1,xunknown8 param_2,xunknown8 param_3)

{
  xunknown8 in_stack_00000000;
  xunknown1 axStack8 [8];
  
  (*pcRam0000000000403ff0)
            (main,in_stack_00000000,&stack0x00000008,__libc_csu_init,__libc_csu_fini,param_3,
             axStack8);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

/* WARNING: Removing unreachable block (ram,0x004011bd) */
/* WARNING: Removing unreachable block (ram,0x004011c7) */

void deregister_tm_clones(void)

{
  return;
}

/* WARNING: Removing unreachable block (ram,0x004011ff) */
/* WARNING: Removing unreachable block (ram,0x00401209) */

void register_tm_clones(void)

{
  return;
}

void __do_global_dtors_aux(void)

{
  if (cRam00000000004040a0 == '\0') {
    deregister_tm_clones();
    cRam00000000004040a0 = 1;
    return;
  }
  return;
}

/* WARNING: Removing unreachable block (ram,0x004011ff) */
/* WARNING: Removing unreachable block (ram,0x00401209) */

void frame_dummy(void)

{
  return;
}

void test1(void)

{
  sumArray(xRam0000000000404020,0x404040);
                    /* WARNING: Could not recover jumptable at 0x00401050. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0000000000403fe0)(1,0x402004);
  return;
}

void test2(void)

{
  maxArray(xRam0000000000404020,0x404040);
                    /* WARNING: Could not recover jumptable at 0x00401050. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0000000000403fe0)(1,0x402012);
  return;
}

void test3(void)

{
  minArray(xRam0000000000404020,0x404040);
                    /* WARNING: Could not recover jumptable at 0x00401050. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0000000000403fe0)(1,0x402020);
  return;
}

void test4(void)

{
  xunknown4 xVar1;
  
  xVar1 = findArray(xRam00000000004020d0,xRam00000000004020c8,xRam0000000000404020,0x404040);
                    /* WARNING: Could not recover jumptable at 0x00401050. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0000000000403fe0)(1,0x40202e,xVar1);
  return;
}

void test5(void)

{
  xunknown8 *pxVar1;
  xunknown8 xVar2;
  xunknown8 *pxVar3;
  xunknown8 *pxVar4;
  
  pxVar1 = (xunknown8 *)((int8)xRam0000000000404020 * 8 + 0x404040);
  if ((xunknown8 *)0x404040 < pxVar1) {
    pxVar4 = (xunknown8 *)0x404040;
    do {
      xVar2 = *pxVar4;
      pxVar3 = pxVar4 + -0x80808;
      pxVar4 = pxVar4 + 1;
      func_0x00401050(xVar2,1,0x4020d8,(int8)pxVar3 >> 3);
    } while (pxVar4 < pxVar1);
  }
  return;
}

void test6(void)

{
  xunknown8 *pxVar1;
  xunknown8 xVar2;
  xunknown8 *pxVar3;
  xunknown8 *pxVar4;
  
  printArray(xRam0000000000404020,0x404040);
  func_0x00401030();
  sortArray(xRam0000000000404020,0x404040);
  pxVar1 = (xunknown8 *)((int8)xRam0000000000404020 * 8 + 0x404040);
  if ((xunknown8 *)0x404040 < pxVar1) {
    pxVar4 = (xunknown8 *)0x404040;
    do {
      xVar2 = *pxVar4;
      pxVar3 = pxVar4 + -0x80808;
      pxVar4 = pxVar4 + 1;
      func_0x00401050(xVar2,1,0x4020d8,(int8)pxVar3 >> 3);
    } while (pxVar4 < pxVar1);
  }
  return;
}

void sumArray(int4 param_1,uint8 param_2)

{
  uint8 uVar1;
  
  uVar1 = param_2 + (int8)param_1 * 8;
  if (param_2 < uVar1) {
    do {
      param_2 = param_2 + 8;
    } while (param_2 < uVar1);
    return;
  }
  return;
}

uint8 maxArray(int4 param_1,uint8 *param_2)

{
  uint8 *puVar1;
  uint8 uVar2;
  xunknown8 xVar3;
  xunknown1 axVar4 [16];
  
  uVar2 = *param_2;
  xVar3 = 0;
  puVar1 = param_2 + param_1;
  if (puVar1 <= param_2) {
    return uVar2;
  }
  while (param_2 = param_2 + 1, param_2 < puVar1) {
    axVar4 = maxsd(ZEXT816(*param_2),CONCAT88(xVar3,uVar2));
    uVar2 = SUB168(axVar4,0);
    xVar3 = SUB168(axVar4 >> 0x40,0);
  }
  return uVar2;
}

uint8 minArray(int4 param_1,uint8 *param_2)

{
  uint8 *puVar1;
  uint8 uVar2;
  xunknown8 xVar3;
  xunknown1 axVar4 [16];
  
  uVar2 = *param_2;
  xVar3 = 0;
  puVar1 = param_2 + param_1;
  if (puVar1 <= param_2) {
    return uVar2;
  }
  while (param_2 = param_2 + 1, param_2 < puVar1) {
    axVar4 = minsd(ZEXT816(*param_2),CONCAT88(xVar3,uVar2));
    uVar2 = SUB168(axVar4,0);
    xVar3 = SUB168(axVar4 >> 0x40,0);
  }
  return uVar2;
}

int8 findArray(float8 param_1,float8 param_2,int4 param_3,float8 *param_4)

{
  float8 *pfVar1;
  
  pfVar1 = param_4;
  if (param_4 < param_4 + param_3) {
    do {
      if ((*pfVar1 <= param_2) && (param_1 <= *pfVar1)) {
        return (int8)((int8)pfVar1 - (int8)param_4) >> 3;
      }
      pfVar1 = pfVar1 + 1;
    } while (pfVar1 < param_4 + param_3);
  }
  return 0xffffffff;
}

void sortArray(int4 param_1,float8 *param_2)

{
  float8 *pfVar1;
  float8 fVar2;
  float8 *pfVar3;
  
  pfVar1 = param_2 + param_1;
  if (param_2 < pfVar1) {
    param_2 = param_2 + 1;
    while (pfVar3 = param_2, param_2 < pfVar1) {
      do {
        fVar2 = param_2[-1];
        if (*pfVar3 < fVar2) {
          param_2[-1] = *pfVar3;
          *pfVar3 = fVar2;
        }
        pfVar3 = pfVar3 + 1;
      } while (pfVar3 < pfVar1);
      param_2 = param_2 + 1;
    }
  }
  return;
}

void printArray(int4 param_1,xunknown8 *param_2)

{
  xunknown8 *pxVar1;
  xunknown8 *pxVar2;
  
  pxVar1 = param_2;
  if (param_2 < param_2 + param_1) {
    do {
      pxVar2 = pxVar1 + 1;
      func_0x00401050(*pxVar1,1,0x4020d8,(int8)((int8)pxVar1 - (int8)param_2) >> 3);
      pxVar1 = pxVar2;
    } while (pxVar2 < param_2 + param_1);
  }
  return;
}

void __libc_csu_init(xunknown4 param_1,xunknown8 param_2,xunknown8 param_3)

{
  int8 iVar1;
  
  _init();
  iVar1 = 0;
  do {
    (**(code **)(iVar1 * 8 + 0x403d98))(param_1,param_2,param_3);
    iVar1 = iVar1 + 1;
  } while (iVar1 != 1);
  return;
}

void __libc_csu_fini(void)

{
  return;
}

void _fini(void)

{
  return;
}
