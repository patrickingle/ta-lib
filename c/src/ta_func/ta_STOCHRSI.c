/* TA-LIB Copyright (c) 1999-2003, Mario Fortier
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 *
 * - Neither name of author nor the names of its contributors
 *   may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* List of contributors:
 *
 *  Initial  Name/description
 *  -------------------------------------------------------------------
 *  MF       Mario Fortier
 *  PP       Peter Pudaite
 *
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  120802 MF   Template creation.
 *  240903 PP   Initial creation of code.
 *
 */

/**** START GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
/* All code within this section is automatically
 * generated by gen_code. Any modification will be lost
 * next time gen_code is run.
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */    #using <mscorlib.dll>
/* Generated */    #include "Core.h"
/* Generated */    namespace TA { namespace Lib {
/* Generated */ #else
/* Generated */    #include <string.h>
/* Generated */    #include <math.h>
/* Generated */    #include "ta_func.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #ifndef TA_UTILITY_H
/* Generated */    #include "ta_utility.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #ifndef TA_MEMORY_H
/* Generated */    #include "ta_memory.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #define TA_PREFIX(x) TA_##x
/* Generated */ #define INPUT_TYPE   double
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ int Core::STOCHRSI_Lookback( int           optInFastK_Period_0, /* From 1 to 100000 */
/* Generated */                            int           optInFastD_Period_1, /* From 1 to 100000 */
/* Generated */                            TA_MAType     optInFastD_MAType_2 ) /* Generated */ 
/* Generated */ #else
/* Generated */ int TA_STOCHRSI_Lookback( int           optInFastK_Period_0, /* From 1 to 100000 */
/* Generated */                         int           optInFastD_Period_1, /* From 1 to 100000 */
/* Generated */                         TA_MAType     optInFastD_MAType_2 ) /* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */
   return 0;
}

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_STOCHRSI - Stochastic Relative Strength Index
 * 
 * Input  = double
 * Output = double, double
 * 
 * Optional Parameters
 * -------------------
 * optInFastK_Period_0:(From 1 to 100000)
 *    Time period for building the Fast-K line
 * 
 * optInFastD_Period_1:(From 1 to 100000)
 *    Smoothing for making the Fast-D line. Usually set to 3
 * 
 * optInFastD_MAType_2:
 *    Type of Moving Average for Fast-D
 * 
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum Core::TA_RetCode Core::STOCHRSI( int    startIdx,
/* Generated */                                       int    endIdx,
/* Generated */                                       double       inReal_0 __gc [],
/* Generated */                                       int           optInFastK_Period_0, /* From 1 to 100000 */
/* Generated */                                       int           optInFastD_Period_1, /* From 1 to 100000 */
/* Generated */                                       TA_MAType     optInFastD_MAType_2,
/* Generated */                                       [OutAttribute]Int32 *outBegIdx,
/* Generated */                                       [OutAttribute]Int32 *outNbElement,
/* Generated */                                       double        outFastK_0 __gc [],
/* Generated */                                       double        outFastD_1 __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_STOCHRSI( int    startIdx,
/* Generated */                         int    endIdx,
/* Generated */                         const double inReal_0[],
/* Generated */                         int           optInFastK_Period_0, /* From 1 to 100000 */
/* Generated */                         int           optInFastD_Period_1, /* From 1 to 100000 */
/* Generated */                         TA_MAType     optInFastD_MAType_2,
/* Generated */                         int          *outBegIdx,
/* Generated */                         int          *outNbElement,
/* Generated */                         double        outFastK_0[],
/* Generated */                         double        outFastD_1[] )
/* Generated */ #endif
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
   /* insert local variable here */

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */ 
/* Generated */    /* Validate the requested output range. */
/* Generated */    if( startIdx < 0 )
/* Generated */       return TA_OUT_OF_RANGE_START_INDEX;
/* Generated */    if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */       return TA_OUT_OF_RANGE_END_INDEX;
/* Generated */ 
/* Generated */    /* Validate the parameters. */
/* Generated */    if( !inReal_0 ) return TA_BAD_PARAM;
/* Generated */    /* min/max are checked for optInFastK_Period_0. */
/* Generated */    if( (int)optInFastK_Period_0 == TA_INTEGER_DEFAULT )
/* Generated */       optInFastK_Period_0 = 5;
/* Generated */    else if( ((int)optInFastK_Period_0 < 1) || ((int)optInFastK_Period_0 > 100000) )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    /* min/max are checked for optInFastD_Period_1. */
/* Generated */    if( (int)optInFastD_Period_1 == TA_INTEGER_DEFAULT )
/* Generated */       optInFastD_Period_1 = 3;
/* Generated */    else if( ((int)optInFastD_Period_1 < 1) || ((int)optInFastD_Period_1 > 100000) )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    #if !defined(_MANAGED)
/* Generated */    if( (int)optInFastD_MAType_2 == TA_INTEGER_DEFAULT )
/* Generated */       optInFastD_MAType_2 = 0;
/* Generated */    else if( ((int)optInFastD_MAType_2 < 0) || ((int)optInFastD_MAType_2 > 8) )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    #endif /* !defined(_MANAGED) */
/* Generated */    if( outFastK_0 == NULL )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( outFastD_1 == NULL )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */
  
   *outBegIdx    = 0;
   *outNbElement = 0;
   return TA_SUCCESS;
}

/**** START GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #define  USE_SINGLE_PRECISION_INPUT
/* Generated */ #if !defined( _MANAGED )
/* Generated */    #undef   TA_PREFIX
/* Generated */    #define  TA_PREFIX(x) TA_S_##x
/* Generated */ #endif
/* Generated */ #undef   INPUT_TYPE
/* Generated */ #define  INPUT_TYPE float
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum Core::TA_RetCode Core::STOCHRSI( int    startIdx,
/* Generated */                                       int    endIdx,
/* Generated */                                       float        inReal_0 __gc [],
/* Generated */                                       int           optInFastK_Period_0, /* From 1 to 100000 */
/* Generated */                                       int           optInFastD_Period_1, /* From 1 to 100000 */
/* Generated */                                       TA_MAType     optInFastD_MAType_2,
/* Generated */                                       [OutAttribute]Int32 *outBegIdx,
/* Generated */                                       [OutAttribute]Int32 *outNbElement,
/* Generated */                                       double        outFastK_0 __gc [],
/* Generated */                                       double        outFastD_1 __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_STOCHRSI( int    startIdx,
/* Generated */                           int    endIdx,
/* Generated */                           const float  inReal_0[],
/* Generated */                           int           optInFastK_Period_0, /* From 1 to 100000 */
/* Generated */                           int           optInFastD_Period_1, /* From 1 to 100000 */
/* Generated */                           TA_MAType     optInFastD_MAType_2,
/* Generated */                           int          *outBegIdx,
/* Generated */                           int          *outNbElement,
/* Generated */                           double        outFastK_0[],
/* Generated */                           double        outFastD_1[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */  #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */     if( startIdx < 0 )
/* Generated */        return TA_OUT_OF_RANGE_START_INDEX;
/* Generated */     if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */        return TA_OUT_OF_RANGE_END_INDEX;
/* Generated */     if( !inReal_0 ) return TA_BAD_PARAM;
/* Generated */     if( (int)optInFastK_Period_0 == TA_INTEGER_DEFAULT )
/* Generated */        optInFastK_Period_0 = 5;
/* Generated */     else if( ((int)optInFastK_Period_0 < 1) || ((int)optInFastK_Period_0 > 100000) )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( (int)optInFastD_Period_1 == TA_INTEGER_DEFAULT )
/* Generated */        optInFastD_Period_1 = 3;
/* Generated */     else if( ((int)optInFastD_Period_1 < 1) || ((int)optInFastD_Period_1 > 100000) )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     #if !defined(_MANAGED)
/* Generated */     if( (int)optInFastD_MAType_2 == TA_INTEGER_DEFAULT )
/* Generated */        optInFastD_MAType_2 = 0;
/* Generated */     else if( ((int)optInFastD_MAType_2 < 0) || ((int)optInFastD_MAType_2 > 8) )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     #endif 
/* Generated */     if( outFastK_0 == NULL )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( outFastD_1 == NULL )
/* Generated */        return TA_BAD_PARAM;
/* Generated */  #endif 
/* Generated */    *outBegIdx    = 0;
/* Generated */    *outNbElement = 0;
/* Generated */    return TA_SUCCESS;
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }} // Close namespace TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

