 //## begin module%49D1BD8A02BF.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%49D1BD8A02BF.cm

//## begin module%49D1BD8A02BF.cp preserve=no
//## end module%49D1BD8A02BF.cp

//## Module: CFFT%49D1BD8A02BF; Package specification
//## Subsystem: <Top Level>
//## Source file: C:\Documents and Settings\bfzhou\My Documents\zbf\Research\2dplatform\Anisotropic Noise\CFFT.h

#ifndef CFFT_h
#define CFFT_h 1

//## begin module%49D1BD8A02BF.additionalIncludes preserve=no
//## end module%49D1BD8A02BF.additionalIncludes

//## begin module%49D1BD8A02BF.includes preserve=yes
#include "CRawImage16.H"
//## end module%49D1BD8A02BF.includes

// 3dViewer
#include "3dViewer.h"
//## begin module%49D1BD8A02BF.declarations preserve=no
//## end module%49D1BD8A02BF.declarations

//## begin module%49D1BD8A02BF.additionalDeclarations preserve=yes
//## end module%49D1BD8A02BF.additionalDeclarations


//## begin CFFT%49BEF91301B4.preface preserve=yes
//## end CFFT%49BEF91301B4.preface

//## Class: CFFT%49BEF91301B4
//	## Uses: <unnamed>%3886CE2202E3;CRawImage16 { -> }
//## Category: Reverse Engineered::3dViewer%49BEF911008C
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%49D1CEF400AB;CRawImage16 { -> }

class CFFT 
{
  //## begin CFFT%49BEF91301B4.initialDeclarations preserve=yes
  //## end CFFT%49BEF91301B4.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CFFT%49BEF91301FB
      //	## Constructors (generated)
      CFFT ();

    //## Destructor (specified)
      //## Operation: ~CFFT%49BEF91301FA
      //	## Destructor (specified)
      //	## Operation: ~CFFT%3886AF6E009C
      ~CFFT ();


    //## Other Operations (specified)
      //## Operation: iCalcFrequency%49BEF91301E2
      void iCalcFrequency (WORD NumSamples, WORD FrequencyIndex, double* lpRealIn, double* lpImagIn, double& RealOut, double& ImagOut);

      //## Operation: IDFT%49BEF91301E9
      //	 Additional Public Declarations
      //	## begin CFFT%388682310134.public preserve=yes
      void IDFT (double* dR, double* dI, int m);

      //## Operation: CopyPeridogram%49BEF91301F0
      //	## Operation: CopyPeridogram%3B6111FE03E3
      void CopyPeridogram ();

      //## Operation: MeanGrayOf_image%49BEF91301F1
      //	## Operation: MeanGrayOf_image%3B60C90C0034
      //		Calculateing the mean gray of the image contained in the
      //		member variable 'image'.
      double MeanGrayOf_image ();

      //## Operation: CopyPhaseAngle%49BEF91301F2
      //	## Operation: CopyPhaseAngle%388D15F200C7
      void CopyPhaseAngle ();

      //## Operation: CopyMagnitude%49BEF91301F3
      //	## Operation: CopyMagnitude%388D15CA03D6
      void CopyMagnitude (bool bShiftImg = true);

      //## Operation: CopyImagnary%49BEF91301F4
      //	## Operation: CopyImagnary%388D137B0282
      void CopyImagnary ();

      //## Operation: CopyReal%49BEF91301F5
      //	## Operation: CopyReal%388D136D030E
      void CopyReal ();

      //## Operation: SetWorkingImage%49BEF91301F6
      //	## Operation: SetWorkingImage%3886CC990143
      void SetWorkingImage (CRawImage16* lpCRawFTImage);

      //## Operation: IFFT2D%49BEF91301F8
      //	## Operation: IFFT2D%3886827A02C0
      void IFFT2D ();

      //## Operation: FFT2D%49BEF91301F9
      //	## Other Operations (specified)
      //	## Operation: FFT2D%3886826F021A
      //		      //	2-dimensional FFT Calculation Program
      //		      void FFT2D ();
      void FFT2D ();

    // Data Members for Class Attributes

      //## Attribute: zi%49BEF91301CE
      //	## Attribute: zi%3886AEF201B6
      //	## begin CFFT::zi%3886AEF201B6.attr preserve=no  public:
      //	float* {UA} NULL
      //## begin CFFT::zi%49BEF91301CE.attr preserve=no  public: float* {UA} NULL
      float* zi;
      //## end CFFT::zi%49BEF91301CE.attr

      //## Attribute: zr%49BEF91301CF
      //	## Attribute: zr%3886AEE301E6
      //	## begin CFFT::zr%3886AEE301E6.attr preserve=no  public:
      //	float* {UA} NULL
      //## begin CFFT::zr%49BEF91301CF.attr preserve=no  public: float* {UA} NULL
      float* zr;
      //## end CFFT::zr%49BEF91301CF.attr

      //## Attribute: m_N%49BEF91301D5
      //	## begin CFFT::m_N%3890EA710285.attr preserve=no
      //	public: int {UA} 64
      //## begin CFFT::m_N%49BEF91301D5.attr preserve=no  public: int {UA} 64
      int m_N;
      //## end CFFT::m_N%49BEF91301D5.attr

      //## Attribute: m_M%49BEF91301D6
      //	## Attribute: m_M%3886914C02CD
      //		Image size:   m_M x m_n
      //		i.e.: m_M rows and m_N columns
      //	## begin CFFT::m_M%3886914C02CD.attr preserve=no
      //	public: int {UA} 64
      //## begin CFFT::m_M%49BEF91301D6.attr preserve=no  public: int {UA} 64
      int m_M;
      //## end CFFT::m_M%49BEF91301D6.attr

      //## Attribute: image%49D1CA5400CB
      //## begin CFFT::image%49D1CA5400CB.attr preserve=no  public: unsigned _int16* {UA} 
      unsigned _int16* image;
      //## end CFFT::image%49D1CA5400CB.attr

      //## Attribute: m_dblMeanGrayOfSourceImage%49D1CD79032C
      //## begin CFFT::m_dblMeanGrayOfSourceImage%49D1CD79032C.attr preserve=no  public: double {UA} 128.0
      double m_dblMeanGrayOfSourceImage;
      //## end CFFT::m_dblMeanGrayOfSourceImage%49D1CD79032C.attr

    // Additional Public Declarations
      //## begin CFFT%49BEF91301B4.public preserve=yes
	  void CFFT::CalcFrequency (WORD NumSamples, WORD FrequencyIndex, double* lpRealIn, double* lpImagIn, double& RealOut, double& ImagOut);
//	  void IDFT (double* dR, double* dI, int m);
//	  void iCalcFrequency (WORD NumSamples, WORD FrequencyIndex, double* lpRealIn, double* lpImagIn, double& RealOut, double& ImagOut);
 
      //## end CFFT%49BEF91301B4.public
  protected:
    // Additional Protected Declarations
      //## begin CFFT%49BEF91301B4.protected preserve=yes
      //## end CFFT%49BEF91301B4.protected

  private:

    //## Other Operations (specified)
      //## Operation: DFT%49BEF91301D7
      //	## Operation: DFT%388E5501012D
      void DFT (double* dR, double* dI, int m);

      //## Operation: FFT%49BEF91301DB
      //	## Other Operations (specified)
      //	## Operation: FFT%388682BD03AD
      //		Purpose: Performaing 1-dimensional FFT
      //		Arguments:
      //		A	-- FFT origin / result real part
      //		B	-- FFT origin / result imagine part
      void FFT (double* A, double* B, int m);

    // Data Members for Class Attributes

      //## Attribute: m_fMinImagnary%49BEF91301CA
      //	## Attribute: m_fMinImagnary%388D16FE0271
      //	## begin CFFT::m_fMinImagnary%388D16FE0271.attr
      //	preserve=no  private: float {UA} FLT_MAX
      //## begin CFFT::m_fMinImagnary%49BEF91301CA.attr preserve=no  private: float {UA} FLT_MAX
      float m_fMinImagnary;
      //## end CFFT::m_fMinImagnary%49BEF91301CA.attr

      //## Attribute: m_fMaxImagnary%49BEF91301CB
      //	## Attribute: m_fMaxImagnary%388D16DD0115
      //	## begin CFFT::m_fMaxImagnary%388D16DD0115.attr
      //	preserve=no  private: float {UA} FLT_MIN
      //## begin CFFT::m_fMaxImagnary%49BEF91301CB.attr preserve=no  private: float {UA} FLT_MIN
      float m_fMaxImagnary;
      //## end CFFT::m_fMaxImagnary%49BEF91301CB.attr

      //## Attribute: m_fMinReal%49BEF91301CC
      //	## Attribute: m_fMinReal%388D16D200DD
      //	## begin CFFT::m_fMinReal%388D16D200DD.attr preserve=no
      //	private: float {UA} FLT_MAX
      //## begin CFFT::m_fMinReal%49BEF91301CC.attr preserve=no  private: float {UA} FLT_MAX
      float m_fMinReal;
      //## end CFFT::m_fMinReal%49BEF91301CC.attr

      //## Attribute: m_fMaxReal%49BEF91301CD
      //	## Attribute: m_fMaxReal%388D10060103
      //	## begin CFFT::m_fMaxReal%388D10060103.attr preserve=no
      //	private: float {UA} FLT_MIN
      //## begin CFFT::m_fMaxReal%49BEF91301CD.attr preserve=no  private: float {UA} FLT_MIN
      float m_fMaxReal;
      //## end CFFT::m_fMaxReal%49BEF91301CD.attr

    // Additional Private Declarations
      //## begin CFFT%49BEF91301B4.private preserve=yes
      //## end CFFT%49BEF91301B4.private

  private: //## implementation
    // Data Members for Associations

      //## Association: Reverse Engineered::3dViewer::<unnamed>%49BEF91301C5
      //## Role: CFFT::m_lpCRawFTImage%49BEF91301C7
      //	## Attribute: m_lpCRawFTImage%3886CCE20102
      //	## begin CFFT::m_lpCRawFTImage%3886CCE20102.attr
      //	preserve=no  private: CRawImage16* {UA}
      //## begin CFFT::m_lpCRawFTImage%49BEF91301C7.role preserve=no  private: CRawImage16 { -> RHN}
      CRawImage16 *m_lpCRawFTImage;
      //## end CFFT::m_lpCRawFTImage%49BEF91301C7.role


    // Additional Implementation Declarations
      //## begin CFFT%49BEF91301B4.implementation preserve=yes
      //## end CFFT%49BEF91301B4.implementation

};

//## begin CFFT%49BEF91301B4.postscript preserve=yes
//## end CFFT%49BEF91301B4.postscript

// Class CFFT 

//## begin module%49D1BD8A02BF.epilog preserve=yes
//## end module%49D1BD8A02BF.epilog


#endif
