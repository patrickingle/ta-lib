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
 *  JV       Jesus Viver <324122@cienz.unizar.es>
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  112400 MF   Template creation.
 *  100502 JV   Speed optimization of the algorithm
 */

#include <math.h>

/**** START GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
/* All code within this section is automatically
 * generated by gen_code. Any modification will be lost
 * next time gen_code is run.
 */

#ifndef TA_FUNC_H
   #include "ta_func.h"
#endif

#ifndef TA_UTILITY_H
   #include "ta_utility.h"
#endif

int TA_STDDEV_Lookback( int           optInTimePeriod_0, /* From 2 to TA_INTEGER_MAX */
                        double        optInNbDev_1 )  /* From TA_REAL_MIN to TA_REAL_MAX */

/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */

   /* Lookback is driven by the variance. */
   return TA_VAR_Lookback( optInTimePeriod_0, optInNbDev_1 );
}

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_STDDEV - Standard Deviation
 * 
 * Input  = double
 * Output = double
 * 
 * Optional Parameters
 * -------------------
 * optInTimePeriod_0:(From 2 to TA_INTEGER_MAX)
 *    Number of period
 * 
 * optInNbDev_1:(From TA_REAL_MIN to TA_REAL_MAX)
 *    Nb of deviations
 * 
 * 
 */

TA_RetCode TA_STDDEV( int    startIdx,
                      int    endIdx,
                      const double inReal_0[],
                      int           optInTimePeriod_0, /* From 2 to TA_INTEGER_MAX */
                      double        optInNbDev_1, /* From TA_REAL_MIN to TA_REAL_MAX */
                      int          *outBegIdx,
                      int          *outNbElement,
                      double        outReal_0[] )
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
   /* Insert local variables here. */
   TA_Integer i;
   TA_RetCode retCode;

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

#ifndef TA_FUNC_NO_RANGE_CHECK

   /* Validate the requested output range. */
   if( startIdx < 0 )
      return TA_OUT_OF_RANGE_START_INDEX;
   if( (endIdx < 0) || (endIdx < startIdx))
      return TA_OUT_OF_RANGE_END_INDEX;

   /* Validate the parameters. */
   if( !inReal_0 ) return TA_BAD_PARAM;
   /* min/max are checked for optInTimePeriod_0. */
   if( (int)optInTimePeriod_0 == TA_INTEGER_DEFAULT )
      optInTimePeriod_0 = 5;
   else if( ((int)optInTimePeriod_0 < 2) || ((int)optInTimePeriod_0 > 2147483647) )
      return TA_BAD_PARAM;

   if( optInNbDev_1 == TA_REAL_DEFAULT )
      optInNbDev_1 = 1.000000e+0;
   else if( (optInNbDev_1 < -3.000000e+37) || (optInNbDev_1 > 3.000000e+37) )
      return TA_BAD_PARAM;

   if( outReal_0 == NULL )
      return TA_BAD_PARAM;

#endif /* TA_FUNC_NO_RANGE_CHECK */

/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */

   /* Calculate the variance. */
   retCode = TA_INT_VAR( startIdx,
                         endIdx,
                         inReal_0,
                         optInTimePeriod_0,
                         outBegIdx, outNbElement, outReal_0 );

   if( retCode != TA_SUCCESS )
      return retCode;

   /* Calculate the square root of each variance, this
    * is the standard deviation.
    *
    * Multiply also by the ratio specified.
    */
   if( optInNbDev_1 != 1.0 )
   {
      for( i=0; i < *outNbElement; i++ )
         outReal_0[i] = sqrt(outReal_0[i]) * optInNbDev_1;
   }
   else
   {
      for( i=0; i < *outNbElement; i++ )
         outReal_0[i] = sqrt(outReal_0[i]);
   }

   return TA_SUCCESS;
}

/* The inMovAvg is the moving average of the inReal. 
 *
 * inMovAvgBegIdx is relative to inReal, in other word
 * this is the 'outBegIdx' who was returned when doing the
 * MA on the inReal.
 *
 * inMovAvgNbElement is the number of element who was returned
 * when doing the MA on the inReal.
 *
 * Note: This function is not used by TA_STDDEV, since TA_STDDEV
 *       is optimized considering it uses always a simple moving
 *       average. Still the function is put here because it is 
 *       closely related.
 */
void TA_INT_stddev_using_precalc_ma( const double *inReal,
                                     const double *inMovAvg,
                                     TA_Integer inMovAvgBegIdx,                                    
                                     TA_Integer inMovAvgNbElement,
                                     TA_Integer timePeriod,
                                     double *output )
{
   double tempReal, periodTotal2, meanValue2;
   int outIdx;

   /* Start/end index for sumation. */
   int startSum, endSum;

   startSum = 1+inMovAvgBegIdx-timePeriod;
   endSum = inMovAvgBegIdx;

   periodTotal2 = 0;

   for( outIdx = startSum; outIdx < endSum; outIdx++)
   {
      tempReal = inReal[outIdx];
      tempReal *= tempReal;
      periodTotal2 += tempReal;
   }

   for( outIdx=0; outIdx < inMovAvgNbElement; outIdx++, startSum++, endSum++ )
   {
      tempReal = inReal[endSum];
      tempReal *= tempReal;
      periodTotal2 += tempReal;
      meanValue2 = periodTotal2/timePeriod;

      tempReal = inReal[startSum];
      tempReal *= tempReal;
      periodTotal2 -= tempReal;

      tempReal = inMovAvg[outIdx];
      tempReal *= tempReal;
      output[outIdx] = sqrt( meanValue2-tempReal );
   }
}

