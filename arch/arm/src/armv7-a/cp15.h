/************************************************************************************
 * arch/arm/src/armv7-a/cp15.h
 * CP15 register access
 *
 *   Copyright (C) 2013 Gregory Nutt. All rights reserved.
 *   Authors: Gregory Nutt <gnutt@nuttx.org>
 *
 * References:
 *
 *  "Cortex-A5� MPCore, Technical Reference Manual", Revision: r0p1, Copyright � 2010
 *   ARM. All rights reserved. ARM DDI 0434B (ID101810)
 *  "ARM� Architecture Reference Manual, ARMv7-A and ARMv7-R edition", Copyright �
 *   1996-1998, 2000, 2004-2012 ARM. All rights reserved. ARM DDI 0406C.b (ID072512)
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ************************************************************************************/

#ifndef __ARCH_ARM_SRC_ARMV7_A_CP15_H
#define __ARCH_ARM_SRC_ARMV7_A_CP15_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/
/* System control register descriptions.
 *
 * CP15 registers are accessed with MRC and MCR instructions as follows:
 *
 *  MRC p15, <Op1>, <Rd>, <CRn>, <CRm>, <Op2> ; Read CP15 Register
 *  MCR p15, <Op1>, <Rd>, <CRn>, <CRm>, <Op2> ; Write CP15 Register
 *
 * Where
 *  
 *   <Op1> is the Opcode_1 value for the register
 *   <Rd>  is a general purpose register
 *   <CRn> is the register number within CP15
 *   <CRm> is the operational register
 *   <Op2> is the Opcode_2 value for the register.
 *
 * Reference: Cortex-A5� MPCore, Technical Reference Manual, Paragraph 4.2.
 */

#define _CP15(op1,rd,crn,crm,op2) p15, op1, rd, crn, crm, op2

#define CP15_MIDR(r)       _CP15(0, r, c0, c0, 0)   /* Main ID Register */
#define CP15_TR(r)         _CP15(0, r, c0, c0, 1)   /* Cache Type Register */
#define CP15_TCMTR(r)      _CP15(0, r, c0, c0, 2)   /* TCM Type Register */
#define CP15_TLBTR(r)      _CP15(0, r, c0, c0, 3)   /* TLB Type Register */
#define CP15_MPIDR(r)      _CP15(0, r, c0, c0, 5)   /* Multiprocessor Affinity Register */
#define CP15_MID_PFR0(r)   _CP15(0, r, c0, c1, 0)   /* Processor Feature Register 0 */
#define CP15_MD_PFR1(r)    _CP15(0, r, c0, c1, 1)   /* Processor Feature Register 1 */
#define CP15_MID_DFR0(r)   _CP15(0, r, c0, c1, 2)   /* Debug Feature Register 0 */
#define CP15_MID_MMFR0(r)  _CP15(0, r, c0, c1, 4)   /* Memory Model Features Register 0 */
#define CP15_MID_MMFR1(r)  _CP15(0, r, c0, c1, 5)   /* Memory Model Features Register 1 */
#define CP15_MID_MMFR2(r)  _CP15(0, r, c0, c1, 6)   /* Memory Model Features Register 2 */
#define CP15_MID_MMFR3(r)  _CP15(0, r, c0, c1, 7)   /* Memory Model Features Register 3 */
#define CP15_ID_ISAR0(r)   _CP15(0, r, c0, c2, 0)   /* Instruction Set Attributes Register 0 */
#define CP15_ID_ISAR1(r)   _CP15(0, r, c0, c2, 1)   /* Instruction Set Attributes Register 1 */
#define CP15_ID_ISAR2(r)   _CP15(0, r, c0, c2, 2)   /* Instruction Set Attributes Register 2 */
#define CP15_ID_ISAR3(r)   _CP15(0, r, c0, c2, 3)   /* Instruction Set Attributes Register 3 */
#define CP15_ID_ISAR4(r)   _CP15(0, r, c0, c2, 4)   /* Instruction Set Attributes Register 4 */
#define CP15_ID_ISAR5(r)   _CP15(0, r, c0, c2, 5)   /* Instruction Set Attributes Register 5 */
#define CP15_CCSIDR(r)     _CP15(1, r, c0, c0, 0)   /* Cache Size Identification Register */
#define CP15_CLIDR(r)      _CP15(1, r, c0, c0, 1)   /* Cache Level ID Register */
#define CP15_AIDR(r)       _CP15(1, r, c0, c0, 7)   /* Auxiliary ID Register */
#define CP15_CSSELR(r)     _CP15(2, r, c0, c0, 0)   /* Cache Size Selection Register */

#define CP15_SCTLR(r)      _CP15(0, r, c1, c0, 0)   /* System Control Register */
#define CP15_ACTLR(r)      _CP15(0, r, c1, c0, 1)   /* Auxiliary Control Register */
#define CP15_CPACR(r)      _CP15(0, r, c1, c0, 2)   /* Coprocessor Access Control Register */
#define CP15_SCR(r)        _CP15(0, r, c1, c1, 0)   /* Secure Configuration Register */
#define CP15_SDER(r)       _CP15(0, r, c1, c1, 1)   /* Secure Debug Enable Register */
#define CP15_NSACR(r)      _CP15(0, r, c1, c1, 2)   /* Non-secure Access Control Register */
#define CP15_VCR(r)        _CP15(0, r, c1, c1, 3)   /* Virtualization Control Register */

#define CP15_TTBR0(r)      _CP15(0, r, c2, c0, 0)   /* Translation Table Base Register 0 */
#define CP15_TTBR1(r)      _CP15(0, r, c2, c0, 1)   /* Translation Table Base Register 1 */
#define CP15_TTBCR(r)      _CP15(0, r, c2, c0, 2)   /* Translation Table Base Control Register */

#define CP15_DACR(r)       _CP15(0, r, c3, c0, 0)   /* Domain Access Control Register */

#define CP15_DFSR(r)       _CP15(0, r, c5, c0, 0)   /* Data Fault Status Register */
#define CP15_IFSR(r)       _CP15(0, r, c5, c0, 1)   /* Instruction Fault Status Register */
#define CP15_ADFSR(r)      _CP15(0, r, c5, c1, 0)   /* Auxiliary Data Fault Status Register */
#define CP15_AIFSR(r)      _CP15(0, r, c5, c1, 1)   /* Auxiliary Instruction Fault Status Register */

#define CP15_DFAR(r)       _CP15(0, r, c6, c0, 0)   /* Data Fault Address Register */
#define CP15_IFAR(r)       _CP15(0, r, c6, c0, 2)   /* Instruction Fault Address Register */

#define CP15_NOP(r)        _CP15(0, r, c7, c0, 4)
#define CP15_ICIALLUIS(r)  _CP15(0, r, c7, c1, 0)   /* Cache Operations Registers */
#define CP15_BPIALLIS(r)   _CP15(0, r, c7, c1, 6)
#define CP15_PAR(r)        _CP15(0, r, c7, c4, 0)   /* Physical Address Register */
#define CP15_ICIALLU(r)    _CP15(0, r, c7, c5, 0)   /* Cache Operations Registers */
#define CP15_ICIMVAU(r)    _CP15(0, r, c7, c5, 1)
#define CP15_ISB(r)        _CP15(0, r, c7, c5, 4)
#define CP15_BPIALL(r)     _CP15(0, r, c7, c5, 6)   /* Cache Operations Registers */
#define CP15_BPIMVA(r)     _CP15(0, r, c7, c5, 7)
#define CP15_DCIMVAC(r)    _CP15(0, r, c7, c6, 1)
#define CP15_DCISW(r)      _CP15(0, r, c7, c6, 2)
#define CP15_V2PCWPR(r,n)  _CP15(0, r, c7, c8, (n)) /* VA to PA operations, n=0-3 */
#  define CP15_V2PCWPR0(r) _CP15(0, r, c7, c8, 0)
#  define CP15_V2PCWPR1(r) _CP15(0, r, c7, c8, 1)
#  define CP15_V2PCWPR2(r) _CP15(0, r, c7, c8, 2)
#  define CP15_V2PCWPR3(r) _CP15(0, r, c7, c8, 3)
#define CP15_V2POWPR(r,n)  _CP15(0, r, c7, c8, ((n)+4)) /* n=0-3 */
#  define CP15_V2POWPR0(r) _CP15(0, r, c7, c8, 4)
#  define CP15_V2POWPR1(r) _CP15(0, r, c7, c8, 5)
#  define CP15_V2POWPR2(r) _CP15(0, r, c7, c8, 6)
#  define CP15_V2POWPR3(r) _CP15(0, r, c7, c8, 7)
#define CP15_DCCMVAC(r)    _CP15(0, r, c7, c10, 1)  /* Cache Operations Registers */
#define CP15_DCCSW(r)      _CP15(0, r, c7, c10, 2)
#define CP15_DSB(r)        _CP15(0, r, c7, c10, 4)
#define CP15_DMB(r)        _CP15(0, r, c7, c10, 5)
#define CP15_DCCMVAU(r)    _CP15(0, r, c7, c11, 1)  /* Cache Operations Registers */
#define CP15_DCCIMVAC(r)   _CP15(0, r, c7, c14, 1)
#define CP15_DCCISW(r)     _CP15(0, r, c7, c14, 2)

#define CP15_TLBIALLIS(r)  _CP15(0, r, c8, c3, 0)   /* TLB maintenance operations */
#define CP15_TLBIMVAIS(r)  _CP15(0, r, c8, c3, 1)
#define CP15_TLBIASIDIS(r) _CP15(0, r, c8, c3, 2)
#define CP15_TLBIMVAAIS(r) _CP15(0, r, c8, c3, 3)
#define CP15_TLBIALL(r,c)  _CP15(0, r, c8, c, 0)    /* CRm = c5, c6, or c7 */
#define CP15_TLBIMVA(r,c)  _CP15(0, r, c8, c, 1)    /* CRm = c5, c6, or c7 */
#define CP15_TLBIASID(r,c) _CP15(0, r, c8, c, 2)    /* CRm = c5, c6, or c7 */
#define CP15_TLBIMVAA(r,c) _CP15(0, r, c8, c, 3)    /* CRm = c5, c6, or c7 */

#define CP15_MCR(r)        _CP15(0, r, c9, c12, 0)  /* Performance Monitor Control Register */
#define CP15_PMCNTENSET(r) _CP15(0, r, c9, c12, 1)  /* Count Enable Set Register */
#define CP15_PMCNTENCLR(r) _CP15(0, r, c9, c12, 2)  /* Count Enable Clear Register */
#define CP15_MOVSR(r)      _CP15(0, r, c9, c12, 3)  /* Overflow Flag Status Register */
#define CP15_PMSWINC(r)    _CP15(0, r, c9, c12, 4)  /* Software Increment Register */
#define CP15_PMSELR(r)     _CP15(0, r, c9, c12, 5)  /* Event Counter Selection Register */
#define CP15_PMCEID0(r)    _CP15(0, r, c9, c12, 6)  /* Common Event Identification Registers */
#define CP15_PMCEID1(r)    _CP15(0, r, c9, c12, 7)
#define CP15_PMCCNTR(r)    _CP15(0, r, c9, c13, 0)  /* Cycle Count Register */
#define CP15_PMXEVTYPER(r) _CP15(0, r, c9, c13, 1)  /* Event Type Select Register */
#define CP15_PMCCFILTR(r)  _CP15(0, r, c9, c13, 1)  /* Cycle Count Filter Control Register */
#define CP15_MXEVCNTR(r)   _CP15(0, r, c9, c13, 2)  /* Event Count Registers */
#define CP15_PMUSERENR(r)  _CP15(0, r, c9, c14, 0)  /* User Enable Register */
#define CP15_PMINTENSET(r) _CP15(0, r, c9, c14, 1)  /* Interrupt Enable Set Register */
#define CP15_PMINTENCLR(r) _CP15(0, r, c9, c14, 2)  /* Interrupt Enable Clear Register */

#define CP15_PPRRR(r)      _CP15(0, r, c10, c2, 0)  /* Memory region remap */
#define CP15_PNMRR(r)      _CP15(0, r, c10, c2, 1)

#define CP15_VBAR(r)       _CP15(0, r, c12, c0, 0)  /* Vector Base Address Register */
#define CP15_MVBAR(r)      _CP15(0, r, c12, c0, 1)  /* Monitor Vector Base Address Register */
#define CP15_ISR(r)        _CP15(0, r, c12, c1, 0)  /* Interrupt Status Register */
#define CP15_VIR(r)        _CP15(0, r, c12, c1, 1)  /* Virtualization Interrupt Register */

#define CP15_FCSEIDR(r)    _CP15(0, r, c13, c0, 0)  /* Fast Context Switch Extension (FCSE) not implemented */
#define CP15_CONTEXTIDR(r) _CP15(0, r, c13, c0, 1)  /* Context ID Register */
#define CP15_TPIDRURW(r)   _CP15(0, r, c13, c0, 2)  /* Software Thread ID Registers */
#define CP15_TPIDRURO(r)   _CP15(0, r, c13, c0, 3)
#define CP15_TPIDRPRW(r)   _CP15(0, r, c13, c0, 4)

#define CP15_DR0(r)        _CP15(3, r, c15, c0, 0)  /* Data Register */
#define CP15_DR1(r)        _CP15(3, r, c15, c0, 1)  /* Data Register */
#define CP15_DTAGR(r)      _CP15(3, r, c15, c2, 0)  /* Data Cache Tag Read Operation Register */
#define CP15_ITAGR(r)      _CP15(3, r, c15, c2, 1)  /* Instruction Cache Tag Read Operation Register */
#define CP15_DDATAR(r)     _CP15(3, r, c15, c4, 0)  /* Data Cache Data Read Operation Register */
#define CP15_IDATAR(r)     _CP15(3, r, c15, c4, 1)  /* Instruction Cache Data Read Operation Register */
#define CP15_TLBR(r)       _CP15(3, r, c15, c4, 2)  /* TLB Data Read Operation Register */
#define CP15_CBADDR(r)     _CP15(4, r, c15, c0, 0)  /* Configuration Base Address Register */
#define CP15_TLBHITMAP(r)  _CP15(5, r, c15, c0, 0)  /* TLB access and attributes */

/* System control register descriptions.
 *
 * To be provided
 *
 * Reference: Cortex-A5� MPCore, Technical Reference Manual, Paragraph 4.3.
 */

#endif /* __ARCH_ARM_SRC_ARMV7_A_CP15_H */
