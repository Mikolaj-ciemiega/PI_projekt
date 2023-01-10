//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <iomanip>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *wiadomoscIN;
	TEdit *kluczIN;
	TPanel *wiadomoscOUT;
	TButton *enkrypcja;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label4;
	TButton *dekrypcja;
	void __fastcall enkrypcjaClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
