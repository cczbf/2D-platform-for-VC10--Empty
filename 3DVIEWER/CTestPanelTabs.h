//## begin module%40CFBD470366.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%40CFBD470366.cm

//## begin module%40CFBD470366.cp preserve=no
//## end module%40CFBD470366.cp

//## Module: CTestPanelTabs%40CFBD470366; Package specification
//## Subsystem: <Top Level>
//## Source file: C:\zbf\Research\3dViewer\CTestPanelTabs.h

#ifndef CTestPanelTabs_h
#define CTestPanelTabs_h 1

//## begin module%40CFBD470366.additionalIncludes preserve=no
//## end module%40CFBD470366.additionalIncludes

//## begin module%40CFBD470366.includes preserve=yes
#include "stdafx.h"
//## end module%40CFBD470366.includes

// CDlgTab07
#include "CDlgTab07.h"
// CDlgTab00
#include "CDlgTab00.h"
// CDlgTab02
#include "CDlgTab02.h"
// CDlgTab01
#include "CDlgTab01.h"
// CDlgTab03
#include "CDlgTab03.h"
// CDlgTab04
#include "CDlgTab04.h"
// CDlgTab05
#include "CDlgTab05.h"
// CDlgTab06
#include "CDlgTab06.h"
//## begin module%40CFBD470366.declarations preserve=no
extern const char* cszTabName01;
//#define cszTabName01 "周秉锋"
extern const char* cszOldHalftoneArrayGeneration;
extern const char* cszBalHalftoneArrayTest;
extern const char* cszBalancedHalftoneArrayGen;
extern const char* cszErrorDiffusion;
extern const char* cszPoissonDistribution;
extern const char* cszTemporalTestBed;

extern const char* cszLocalOptimization;
extern const char* cszThAryFromErrorD;

#define N0 0
#define N1 1
#define N2 2
#define N3 3
#define N4 4
#define N5 5
#define N6 6
#define N7 7
#define N8 8
//## end module%40CFBD470366.declarations

//## begin module%40CFBD470366.additionalDeclarations preserve=yes
//## end module%40CFBD470366.additionalDeclarations


//## begin CTestPanelTabs%3690FEB30111.preface preserve=yes
//## end CTestPanelTabs%3690FEB30111.preface

//## Class: CTestPanelTabs%3690FEB30111; Parameterized Class
//	CTestPanelTabs类：
//
//	1. 这个模板类和CDlgTestPanel接口，用于实现各TAB之间切换。
//	2.每个TAB对应一个本模板类的一个实例类，实例类用其实参初始
//	化模板类的形参。
//	3. 模板类里的形参的定义如下：
//	      (1). n
//	Index：整数，唯一标识对应TAB的序号。（以0为基）,在源代码?
//	锎唇═AB时应严格按照此序号的顺序创建。
//	      (2). cszTabLable：字符串常数，内容定义了TAB的标题。
//	      (3).  nDialogID：整数，是TAB对应的对话框的ID
//	      (4). CDlgTab：class,抽象类型,
//	是TAB对应的对话框的处理类的类型。
//## Category: 3dViewer::ShellClasses::CTestPanelTabs_Templete%40CFABAD024C
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n

template <int nIndex, int nDialogID, class CDlgTabContent>
class CTestPanelTabs 
{
  //## begin CTestPanelTabs%3690FEB30111.initialDeclarations preserve=yes
  //## end CTestPanelTabs%3690FEB30111.initialDeclarations

  public:
    //## Constructors (generated)
      CTestPanelTabs();

    //## Destructor (specified)
      //## Operation: ~CTestPanelTabs%3691091D0129
      ~CTestPanelTabs ();


    //## Other Operations (specified)
      //## Operation: CTestPanelTabsInit%369103FD033F
      //	构造函数：CTestPanelTabs(pCTabCtrlParent: CTabCtrl*);
      //	参数：pCTabCtrlParent
      //	     类型：指向对应TAB Control窗口类的指针。
      //	     用途：用它初始化m_pTabCtrlParent成员变量。
      //## Preconditions:
      //	<<>> CTestPanelTabs(pCTabCtrlParent : CTabCtrl*)
      void CTestPanelTabsInit (CTabCtrl* pCTabCtrlParent);

      //## Operation: SetLable%36910C5A006C
      //	Function:
      //	SetLable():void
      //	创建新tab,并为此tab设置标题
      //	此函数只能被构造函数调用
      void SetLable ();

      //## Operation: TabChange%40D3A2F0037C
      void TabChange (CTabCtrl* pCTabCtrl);

      //## Operation: TabChanging%40D3A4A003B9
      void TabChanging (CTabCtrl* pCTabCtrl);

    // Additional Public Declarations
      //## begin CTestPanelTabs%3690FEB30111.public preserve=yes
      //## end CTestPanelTabs%3690FEB30111.public

  protected:
    // Additional Protected Declarations
      //## begin CTestPanelTabs%3690FEB30111.protected preserve=yes
      //## end CTestPanelTabs%3690FEB30111.protected

  private:

    //## Other Operations (specified)
      //## Operation: TabSelecting%36913C5D0200
      //	成员函数： TabSelecting(nTabIndex : int) : BOOL
      //
      //	Call this function when the tab is about to be changed.
      //	Parameter: nTabIndex: Current selected tab.
      //	Return: Changed: TRUE
      //
      //	功能：
      //	本类对应的TAB，即将被退选，所以，将当前选中的TAB对应的对?
//	翱蚬乇铡?
BOOL TabSelecting (int nTabIndex);

      //## Operation: TabSelected%36913F1202CF
      //	成员函数： TabSelected(nTabIndex : int) : BOOL
      //	此函数被调用时，表明本类对应的TAB即将被选中。
      //	因此，在这里创建TAB对应的对话框。
      //## Preconditions:
      //	函数变量nTabIndex必须和模板类形参nIndex相等。
      //## Semantics:
      //	语义：
      BOOL TabSelected (int nTabIndex);

      //## Operation: StartTabSession%36914DEE01C1
      //	函数StartTabSession(pCTabParent : CTabCtrl*) : void
      //	和
      //	EndTabSession() : void
      //
      //	Call this pair of function when you are going to access
      //	the tab control through member functions: ...
      //
      //	由于TAB Control对应的类CTabCtrl指针不是永远有效，
      //	所以在调用父CTabCtrl类的函数时，要调用StartTabSession(p
      //	CTabParent : CTabCtrl*)去
      //	初始化m_pCTabCtrlParent成员变量。在访问CTab
      //	Ctrl结束时，调用EndTabSession()清理现场。
      void StartTabSession (CTabCtrl* pCTabParent);

      //## Operation: EndTabSession%36914E700326
      //	函数StartTabSession(pCTabParent : CTabCtrl*) : void
      //	和
      //	EndTabSession() : void
      //
      //	Call this pair of function when you are going to access
      //	the tab control through member functions: ...
      //
      //	由于TAB Control对应的类CTabCtrl指针不是永远有效，
      //	所以在调用父CTabCtrl类的函数时，要调用StartTabSession(p
      //	CTabParent : CTabCtrl*)去
      //	初始化m_pCTabCtrlParent成员变量。在访问CTab
      //	Ctrl结束时，调用EndTabSession()清理现场。
      void EndTabSession ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: m_nIndex%369108A0010B
      const int get_m_nIndex () const;
      void set_m_nIndex (int value);

      //## Attribute: m_szTabLable%369108CE0111
      const char* get_m_szTabLable () const;
      void set_m_szTabLable (char* value);

      //## Attribute: m_pCTabCtrlParent%36910ADF02AC
      const CTabCtrl* get_m_pCTabCtrlParent () const;
      void set_m_pCTabCtrlParent (CTabCtrl* value);

      //## Attribute: m_pCTabCtrl0%40D3A7200229
      const CTabCtrl* get_m_pCTabCtrl0 () const;
      void set_m_pCTabCtrl0 (CTabCtrl* value);

      //## Attribute: m_pCDlgTabContent%3691156400F6
      const CDlgTabContent* get_m_pCDlgTabContent () const;
      void set_m_pCDlgTabContent (CDlgTabContent* value);

      //## Attribute: m_szLableString%40D23AC602DF
      const char* get_m_szLableString () const;
      void set_m_szLableString (char* value);

    // Additional Private Declarations
      //## begin CTestPanelTabs%3690FEB30111.private preserve=yes
      //## end CTestPanelTabs%3690FEB30111.private

  private: //## implementation
    // Data Members for Class Attributes

      //## begin CTestPanelTabs::m_nIndex%369108A0010B.attr preserve=no  private: int {U} 0
      int m_nIndex;
      //## end CTestPanelTabs::m_nIndex%369108A0010B.attr

      //## begin CTestPanelTabs::m_szTabLable%369108CE0111.attr preserve=no  private: char[128] {U} 
      char m_szTabLable[128];
      //## end CTestPanelTabs::m_szTabLable%369108CE0111.attr

      //## begin CTestPanelTabs::m_pCTabCtrlParent%36910ADF02AC.attr preserve=no  private: CTabCtrl* {U} NULL
      CTabCtrl* m_pCTabCtrlParent;
      //## end CTestPanelTabs::m_pCTabCtrlParent%36910ADF02AC.attr

      //## begin CTestPanelTabs::m_pCTabCtrl0%40D3A7200229.attr preserve=no  private: CTabCtrl* {U} NULL
      CTabCtrl* m_pCTabCtrl0;
      //## end CTestPanelTabs::m_pCTabCtrl0%40D3A7200229.attr

      //## begin CTestPanelTabs::m_pCDlgTabContent%3691156400F6.attr preserve=no  private: CDlgTabContent* {U} NULL
      CDlgTabContent* m_pCDlgTabContent;
      //## end CTestPanelTabs::m_pCDlgTabContent%3691156400F6.attr

      //## begin CTestPanelTabs::m_szLableString%40D23AC602DF.attr preserve=no  private: char* {U} "\\Tab0\\Tab1\\Tab2\\Tab3\\Tab4\\Tab5\\Tab6\\Tab7\\"
      char* m_szLableString;
      //## end CTestPanelTabs::m_szLableString%40D23AC602DF.attr

    // Additional Implementation Declarations
      //## begin CTestPanelTabs%3690FEB30111.implementation preserve=yes
      //## end CTestPanelTabs%3690FEB30111.implementation

};

//## begin CTestPanelTabs%3690FEB30111.postscript preserve=yes
//## end CTestPanelTabs%3690FEB30111.postscript

//## begin CTabHub%40D2B35302F5.preface preserve=yes
//## end CTabHub%40D2B35302F5.preface

//## Class: CTabHub%40D2B35302F5
//## Category: 3dViewer::ShellClasses%3690FDE70367
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CTabHub 
{
  //## begin CTabHub%40D2B35302F5.initialDeclarations preserve=yes
  //## end CTabHub%40D2B35302F5.initialDeclarations

  public:
    //## Constructors (generated)
      CTabHub();

    //## Destructor (generated)
      ~CTabHub();


    //## Other Operations (specified)
      //## Operation: OnInitDialog%40D2B3C90092
      BOOL OnInitDialog (CTabCtrl* pCTabParent);

      //## Operation: OnSelchangeTABTestPanels%40D3A0A8005B
      void OnSelchangeTABTestPanels (NMHDR* pNMHDR, LRESULT* pResult, CTabCtrl* pCTabCtrl);

      //## Operation: OnSelchangingTABTestPanels%40D3A0B902E0
      void OnSelchangingTABTestPanels (NMHDR* pNMHDR, LRESULT* pResult, CTabCtrl* pCTabCtrl);

    // Additional Public Declarations
      //## begin CTabHub%40D2B35302F5.public preserve=yes
      //## end CTabHub%40D2B35302F5.public

  protected:
    // Additional Protected Declarations
      //## begin CTabHub%40D2B35302F5.protected preserve=yes
      //## end CTabHub%40D2B35302F5.protected

  private:
    // Additional Private Declarations
      //## begin CTabHub%40D2B35302F5.private preserve=yes
      //## end CTabHub%40D2B35302F5.private

  private: //## implementation
    // Data Members for Associations

      //## Association: 3dViewer::ShellClasses::<unnamed>%40D001B00319
      //## Role: CTabHub::m_CTestTab01%40D001B101D0
      //## begin CTabHub::m_CTestTab01%40D001B101D0.role preserve=no  public: CTestPanelTabs< N1,IDD_TAB_DIALOG01,CDlgTab01 > { -> VHgN}
      CTestPanelTabs< N1,IDD_TAB_DIALOG01,CDlgTab01 > m_CTestTab01;
      //## end CTabHub::m_CTestTab01%40D001B101D0.role

      //## Association: 3dViewer::ShellClasses::<unnamed>%40D2E3F901CC
      //## Role: CTabHub::m_CTestTab02%40D2E3FA00F1
      //## begin CTabHub::m_CTestTab02%40D2E3FA00F1.role preserve=no  public: CTestPanelTabs< N2,IDD_TAB_DIALOG02,CDlgTab02 > { -> VHgN}
      CTestPanelTabs< N2,IDD_TAB_DIALOG02,CDlgTab02 > m_CTestTab02;
      //## end CTabHub::m_CTestTab02%40D2E3FA00F1.role

      //## Association: 3dViewer::ShellClasses::<unnamed>%40D530C3005C
      //## Role: CTabHub::m_CTestTab00%40D530C40162
      //## begin CTabHub::m_CTestTab00%40D530C40162.role preserve=no  public: CTestPanelTabs< N0,IDD_TAB_DIALOG00,CDlgTab00 > { -> VHgN}
      CTestPanelTabs< N0,IDD_TAB_DIALOG00,CDlgTab00 > m_CTestTab00;
      //## end CTabHub::m_CTestTab00%40D530C40162.role

      //## Association: 3dViewer::ShellClasses::<unnamed>%40D530C703C9
      //## Role: CTabHub::<the_void>%40D530C90123
      //## begin CTabHub::<the_void>%40D530C90123.role preserve=no  public: CTestPanelTabs< N4,IDD_TAB_DIALOG04,CDlgTab04 > { -> UHgN}
      //CTestPanelTabs< N4,IDD_TAB_DIALOG04,CDlgTab04 > the_void;
      //## end CTabHub::<the_void>%40D530C90123.role

      //## Association: 3dViewer::ShellClasses::<unnamed>%40D530CC0312
      //## Role: CTabHub::m_CTestTab05%40D530CE001C
      //## begin CTabHub::m_CTestTab05%40D530CE001C.role preserve=no  public: CTestPanelTabs< N5,IDD_TAB_DIALOG05,CDlgTab05 > { -> VHgN}
      CTestPanelTabs< N5,IDD_TAB_DIALOG05,CDlgTab05 > m_CTestTab05;
      //## end CTabHub::m_CTestTab05%40D530CE001C.role

      //## Association: 3dViewer::ShellClasses::<unnamed>%40D530D30182
      //## Role: CTabHub::m_CTestTab06%40D530D501AD
      //## begin CTabHub::m_CTestTab06%40D530D501AD.role preserve=no  public: CTestPanelTabs< N6,IDD_TAB_DIALOG06,CDlgTab06 > { -> VHgN}
      CTestPanelTabs< N6,IDD_TAB_DIALOG06,CDlgTab06 > m_CTestTab06;
      //## end CTabHub::m_CTestTab06%40D530D501AD.role

      //## Association: 3dViewer::ShellClasses::<unnamed>%40D530DA020E
      //## Role: CTabHub::m_CTestTab04%40D530DC006C
      //## begin CTabHub::m_CTestTab04%40D530DC006C.role preserve=no  public: CTestPanelTabs< N4,IDD_TAB_DIALOG04,CDlgTab04 > { -> VHgN}
      CTestPanelTabs< N4,IDD_TAB_DIALOG04,CDlgTab04 > m_CTestTab04;
      //## end CTabHub::m_CTestTab04%40D530DC006C.role

      //## Association: 3dViewer::ShellClasses::<unnamed>%40D53100017C
      //## Role: CTabHub::\rm_CTestTab07%40D5310101B0
      //## begin CTabHub::\rm_CTestTab07%40D5310101B0.role preserve=no  public: CTestPanelTabs< N7,IDD_TAB_DIALOG07,CDlgTab07 > { -> VHgN}
      CTestPanelTabs< N7,IDD_TAB_DIALOG07,CDlgTab07 > m_CTestTab07;
      //## end CTabHub::\rm_CTestTab07%40D5310101B0.role

      //## Association: 3dViewer::ShellClasses::<unnamed>%40D5314002E7
      //## Role: CTabHub::m_CTestTab03%40D5314200FF
      //## begin CTabHub::m_CTestTab03%40D5314200FF.role preserve=no  public: CTestPanelTabs< N3,IDD_TAB_DIALOG03,CDlgTab03 > { -> VHgN}
      CTestPanelTabs< N3,IDD_TAB_DIALOG03,CDlgTab03 > m_CTestTab03;
      //## end CTabHub::m_CTestTab03%40D5314200FF.role

    // Additional Implementation Declarations
      //## begin CTabHub%40D2B35302F5.implementation preserve=yes
      //## end CTabHub%40D2B35302F5.implementation

};

//## begin CTabHub%40D2B35302F5.postscript preserve=yes
//## end CTabHub%40D2B35302F5.postscript

// Parameterized Class CTestPanelTabs 

//## Get and Set Operations for Class Attributes (inline)

template <int nIndex, int nDialogID, class CDlgTabContent>
inline const int CTestPanelTabs<nIndex,nDialogID,CDlgTabContent>::get_m_nIndex () const
{
  //## begin CTestPanelTabs::get_m_nIndex%369108A0010B.get preserve=no
  return m_nIndex;
  //## end CTestPanelTabs::get_m_nIndex%369108A0010B.get
}

template <int nIndex, int nDialogID, class CDlgTabContent>
inline void CTestPanelTabs<nIndex,nDialogID,CDlgTabContent>::set_m_nIndex (int value)
{
  //## begin CTestPanelTabs::set_m_nIndex%369108A0010B.set preserve=no
  m_nIndex = value;
  //## end CTestPanelTabs::set_m_nIndex%369108A0010B.set
}

template <int nIndex, int nDialogID, class CDlgTabContent>
inline const char* CTestPanelTabs<nIndex,nDialogID,CDlgTabContent>::get_m_szTabLable () const
{
  //## begin CTestPanelTabs::get_m_szTabLable%369108CE0111.get preserve=no
  return m_szTabLable;
  //## end CTestPanelTabs::get_m_szTabLable%369108CE0111.get
}

template <int nIndex, int nDialogID, class CDlgTabContent>
inline void CTestPanelTabs<nIndex,nDialogID,CDlgTabContent>::set_m_szTabLable (char* value)
{
  //## begin CTestPanelTabs::set_m_szTabLable%369108CE0111.set preserve=no
  m_szTabLable = value;
  //## end CTestPanelTabs::set_m_szTabLable%369108CE0111.set
}

template <int nIndex, int nDialogID, class CDlgTabContent>
inline const CTabCtrl* CTestPanelTabs<nIndex,nDialogID,CDlgTabContent>::get_m_pCTabCtrlParent () const
{
  //## begin CTestPanelTabs::get_m_pCTabCtrlParent%36910ADF02AC.get preserve=no
  return m_pCTabCtrlParent;
  //## end CTestPanelTabs::get_m_pCTabCtrlParent%36910ADF02AC.get
}

template <int nIndex, int nDialogID, class CDlgTabContent>
inline void CTestPanelTabs<nIndex,nDialogID,CDlgTabContent>::set_m_pCTabCtrlParent (CTabCtrl* value)
{
  //## begin CTestPanelTabs::set_m_pCTabCtrlParent%36910ADF02AC.set preserve=no
  m_pCTabCtrlParent = value;
  //## end CTestPanelTabs::set_m_pCTabCtrlParent%36910ADF02AC.set
}

template <int nIndex, int nDialogID, class CDlgTabContent>
inline const CTabCtrl* CTestPanelTabs<nIndex,nDialogID,CDlgTabContent>::get_m_pCTabCtrl0 () const
{
  //## begin CTestPanelTabs::get_m_pCTabCtrl0%40D3A7200229.get preserve=no
  return m_pCTabCtrl0;
  //## end CTestPanelTabs::get_m_pCTabCtrl0%40D3A7200229.get
}

template <int nIndex, int nDialogID, class CDlgTabContent>
inline void CTestPanelTabs<nIndex,nDialogID,CDlgTabContent>::set_m_pCTabCtrl0 (CTabCtrl* value)
{
  //## begin CTestPanelTabs::set_m_pCTabCtrl0%40D3A7200229.set preserve=no
  m_pCTabCtrl0 = value;
  //## end CTestPanelTabs::set_m_pCTabCtrl0%40D3A7200229.set
}

template <int nIndex, int nDialogID, class CDlgTabContent>
inline const CDlgTabContent* CTestPanelTabs<nIndex,nDialogID,CDlgTabContent>::get_m_pCDlgTabContent () const
{
  //## begin CTestPanelTabs::get_m_pCDlgTabContent%3691156400F6.get preserve=no
  return m_pCDlgTabContent;
  //## end CTestPanelTabs::get_m_pCDlgTabContent%3691156400F6.get
}

template <int nIndex, int nDialogID, class CDlgTabContent>
inline void CTestPanelTabs<nIndex,nDialogID,CDlgTabContent>::set_m_pCDlgTabContent (CDlgTabContent* value)
{
  //## begin CTestPanelTabs::set_m_pCDlgTabContent%3691156400F6.set preserve=no
  m_pCDlgTabContent = value;
  //## end CTestPanelTabs::set_m_pCDlgTabContent%3691156400F6.set
}

template <int nIndex, int nDialogID, class CDlgTabContent>
inline const char* CTestPanelTabs<nIndex,nDialogID,CDlgTabContent>::get_m_szLableString () const
{
  //## begin CTestPanelTabs::get_m_szLableString%40D23AC602DF.get preserve=no
  return m_szLableString;
  //## end CTestPanelTabs::get_m_szLableString%40D23AC602DF.get
}

template <int nIndex, int nDialogID, class CDlgTabContent>
inline void CTestPanelTabs<nIndex,nDialogID,CDlgTabContent>::set_m_szLableString (char* value)
{
  //## begin CTestPanelTabs::set_m_szLableString%40D23AC602DF.set preserve=no
  m_szLableString = value;
  //## end CTestPanelTabs::set_m_szLableString%40D23AC602DF.set
}

// Class CTabHub 

//## begin module%40CFBD470366.epilog preserve=yes
//## end module%40CFBD470366.epilog


#endif
