/*=========================================================================
 *
 *  Copyright RTK Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#ifndef __rtkCudaScatterGlareCorrectionImageFilter_h
#define __rtkCudaScatterGlareCorrectionImageFilter_h

#include "rtkScatterGlareCorrectionImageFilter.h"
#include "rtkCudaFFTConvolutionImageFilter.h"

namespace rtk
{

/** \class CudaScatterGlareCorrectionImageFilter
 * \brief Implements the scatter glare correction
 *
 * Uses CUFFT for the projection fft and ifft.
 *
 * \test rtkscatterglarefiltertest.cxx
 *
 * \author Simon Rit
 *
 * \ingroup CudaImageToImageFilter
 */
class CudaScatterGlareCorrectionImageFilter :
  public CudaFFTConvolutionImageFilter< ScatterGlareCorrectionImageFilter< itk::CudaImage<float,3>,
                                                                           itk::CudaImage<float,3>,
                                                                           float > >
{
public:
  /** Standard class typedefs. */
  typedef CudaScatterGlareCorrectionImageFilter                       Self;
  typedef ScatterGlareCorrectionImageFilter< itk::CudaImage<float,3>,
                                             itk::CudaImage<float,3>,
                                             float >                  Superclass;
  typedef itk::SmartPointer<Self>                                     Pointer;
  typedef itk::SmartPointer<const Self>                               ConstPointer;

  /** Standard New method. */
  itkNewMacro(Self);

  /** Runtime information support. */
  itkTypeMacro(CudaScatterGlareCorrectionImageFilter, FFTRampImageFilter);

protected:
  rtkcuda_EXPORT CudaScatterGlareCorrectionImageFilter(){}
  ~CudaScatterGlareCorrectionImageFilter(){}

private:
  CudaScatterGlareCorrectionImageFilter(const Self&); //purposely not implemented
  void operator=(const Self&);                        //purposely not implemented
}; // end of class

} // end namespace rtk

#endif