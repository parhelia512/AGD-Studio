﻿// CodeGear C++Builder
// Copyright (c) 1995, 2018 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DosCommand.pas' rev: 33.00 (Windows)

#ifndef DoscommandHPP
#define DoscommandHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <System.SyncObjs.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.Messages.hpp>

//-- user supplied -----------------------------------------------------------

namespace Doscommand
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EDosCommand;
class DELPHICLASS ECreatePipeError;
class DELPHICLASS ECreateProcessError;
class DELPHICLASS EProcessTimer;
class DELPHICLASS TProcessTimer;
class DELPHICLASS TInputLines;
class DELPHICLASS TSyncString;
class DELPHICLASS TReadPipe;
class DELPHICLASS TDosThread;
class DELPHICLASS TDosCommand;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION EDosCommand : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EDosCommand(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EDosCommand(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EDosCommand(NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EDosCommand(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EDosCommand(NativeUInt Ident, const System::TVarRec *Args, const int Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EDosCommand(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EDosCommand(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EDosCommand(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EDosCommand(NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EDosCommand(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EDosCommand(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EDosCommand(NativeUInt Ident, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EDosCommand() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION ECreatePipeError : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall ECreatePipeError(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall ECreatePipeError(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall ECreatePipeError(NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall ECreatePipeError(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall ECreatePipeError(NativeUInt Ident, const System::TVarRec *Args, const int Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall ECreatePipeError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall ECreatePipeError(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall ECreatePipeError(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ECreatePipeError(NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ECreatePipeError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ECreatePipeError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ECreatePipeError(NativeUInt Ident, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~ECreatePipeError() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION ECreateProcessError : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall ECreateProcessError(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall ECreateProcessError(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall ECreateProcessError(NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall ECreateProcessError(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall ECreateProcessError(NativeUInt Ident, const System::TVarRec *Args, const int Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall ECreateProcessError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall ECreateProcessError(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall ECreateProcessError(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ECreateProcessError(NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ECreateProcessError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ECreateProcessError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ECreateProcessError(NativeUInt Ident, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~ECreateProcessError() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EProcessTimer : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EProcessTimer(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EProcessTimer(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EProcessTimer(NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EProcessTimer(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EProcessTimer(NativeUInt Ident, const System::TVarRec *Args, const int Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EProcessTimer(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EProcessTimer(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EProcessTimer(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EProcessTimer(NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EProcessTimer(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EProcessTimer(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EProcessTimer(NativeUInt Ident, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EProcessTimer() { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TOutputType : unsigned char { otEntireLine, otBeginningOfLine };

enum DECLSPEC_DENUM TEndStatus : unsigned char { esStop, esProcess, esStill_Active, esNone, esError, esTime };

typedef System::UnicodeString __fastcall (__closure *TCharDecoding)(System::TObject* ASender, System::Classes::TStream* ABuf);

typedef void __fastcall (__closure *TCharEncoding)(System::TObject* ASender, const System::UnicodeString AChars, System::Classes::TStream* AOutBuf);

#pragma pack(push,4)
class PASCALIMPLEMENTATION TProcessTimer : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Syncobjs::TCriticalSection* FCriticalSection;
	bool FEnabled;
	System::Syncobjs::TEvent* FEvent;
	int FID;
	int FSinceBeginning;
	int FSinceLastOutput;
	int __fastcall get_SinceBeginning();
	int __fastcall get_SinceLastOutput();
	void __fastcall set_Enabled(const bool AValue);
	
private:
	static System::Classes::TThreadList* FTimerInstances;
	void __fastcall MyTimer();
	
private:
	// __classmethod void __fastcall Create@();
	
public:
	__fastcall TProcessTimer();
	
private:
	// __classmethod void __fastcall Destroy@();
	
public:
	__fastcall virtual ~TProcessTimer();
	void __fastcall Beginning();
	void __fastcall Ending();
	void __fastcall NewOutput();
	__property bool Enabled = {read=FEnabled, write=set_Enabled, nodefault};
	__property System::Syncobjs::TEvent* Event = {read=FEvent};
	__property int SinceBeginning = {read=get_SinceBeginning, nodefault};
	__property int SinceLastOutput = {read=get_SinceLastOutput, nodefault};
};

#pragma pack(pop)

typedef void __fastcall (__closure *TNewLineEvent)(System::TObject* ASender, const System::UnicodeString ANewLine, TOutputType AOutputType);

typedef void __fastcall (__closure *TNewCharEvent)(System::TObject* ASender, System::WideChar ANewChar);

typedef void __fastcall (__closure *TErrorEvent)(System::TObject* ASender, System::Sysutils::Exception* AE, bool &AHandled);

typedef void __fastcall (__closure *TTerminateProcessEvent)(System::TObject* ASender, bool &ACanTerminate);

#pragma pack(push,4)
class PASCALIMPLEMENTATION TInputLines : public System::Sysutils::TSimpleRWSync
{
	typedef System::Sysutils::TSimpleRWSync inherited;
	
public:
	System::UnicodeString operator[](int AIndex) { return this->Strings[AIndex]; }
	
private:
	System::Syncobjs::TEvent* FEvent;
	System::Classes::TStrings* FList;
	System::UnicodeString __fastcall get_Strings(int AIndex);
	void __fastcall set_Strings(int AIndex, const System::UnicodeString AValue);
	
public:
	__fastcall TInputLines();
	__fastcall virtual ~TInputLines();
	int __fastcall Add(const System::UnicodeString AValue);
	int __fastcall Count();
	void __fastcall Delete(int AIndex);
	System::Classes::TStrings* __fastcall LockList();
	void __fastcall UnlockList();
	__property System::Syncobjs::TEvent* Event = {read=FEvent};
	__property System::UnicodeString Strings[int AIndex] = {read=get_Strings, write=set_Strings/*, default*/};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TSyncString : public System::Sysutils::TSimpleRWSync
{
	typedef System::Sysutils::TSimpleRWSync inherited;
	
private:
	System::UnicodeString FValue;
	System::UnicodeString __fastcall get_Value();
	void __fastcall set_Value(const System::UnicodeString AValue);
	
public:
	void __fastcall Add(const System::UnicodeString AValue);
	void __fastcall Delete(int APos, int ACount);
	int __fastcall Length();
	__property System::UnicodeString Value = {read=get_Value, write=set_Value};
public:
	/* TSimpleRWSync.Create */ inline __fastcall TSyncString() : System::Sysutils::TSimpleRWSync() { }
	/* TSimpleRWSync.Destroy */ inline __fastcall virtual ~TSyncString() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TReadPipe : public System::Classes::TThread
{
	typedef System::Classes::TThread inherited;
	
private:
	System::Syncobjs::TEvent* FEvent;
	TCharDecoding FOnCharDecoding;
	NativeUInt Fread_stdout;
	NativeUInt Fwrite_stdout;
	TSyncString* FSyncString;
	
protected:
	virtual void __fastcall Execute();
	
public:
	__fastcall TReadPipe(NativeUInt AReadStdout, NativeUInt AWriteStdout, TCharDecoding AOnCharDecoding);
	__fastcall virtual ~TReadPipe();
	HIDESBASE void __fastcall Terminate();
	__property System::Syncobjs::TEvent* Event = {read=FEvent};
	__property TSyncString* ReadString = {read=FSyncString};
};


class PASCALIMPLEMENTATION TDosThread : public System::Classes::TThread
{
	typedef System::Classes::TThread inherited;
	
private:
	System::UnicodeString FCommandLine;
	System::UnicodeString FCurrentDir;
	System::Classes::TStringList* FEnvironment;
	TInputLines* FInputLines;
	bool FInputToOutput;
	System::Classes::TStringList* FLines;
	int FMaxTimeAfterBeginning;
	int FMaxTimeAfterLastOutput;
	TCharDecoding FOnCharDecoding;
	TCharEncoding FOnCharEncoding;
	TNewCharEvent FOnNewChar;
	TNewLineEvent FOnNewLine;
	TTerminateProcessEvent FOnTerminateProcess;
	System::Classes::TStrings* FOutputLines;
	TDosCommand* FOwner;
	int FPriority;
	_PROCESS_INFORMATION FProcessInformation;
	System::Syncobjs::TEvent* FTerminateEvent;
	TProcessTimer* FTimer;
	System::UnicodeString __fastcall DoCharDecoding(System::TObject* ASender, System::Classes::TStream* ABuf);
	void __fastcall DoEndStatus(TEndStatus AValue);
	void __fastcall DoLinesAdd(const System::UnicodeString AStr);
	void __fastcall DoNewChar(System::WideChar AChar);
	void __fastcall DoNewLine(const System::UnicodeString AStr, TOutputType AOutputType);
	void __fastcall DoReadLine(TSyncString* AReadString, System::UnicodeString &AStr, System::UnicodeString &ALast, bool &ALineBeginned);
	void __fastcall DoSendLine(NativeUInt AWritePipe, System::UnicodeString &ALast, bool &ALineBeginned);
	void __fastcall DoTerminateProcess();
	
private:
	unsigned FExitCode;
	
protected:
	bool FCanTerminate;
	virtual void __fastcall Execute();
	
public:
	__fastcall TDosThread(TDosCommand* AOwner, System::UnicodeString ACl, System::UnicodeString ACurrDir, System::Classes::TStringList* ALines, System::Classes::TStrings* AOl, TProcessTimer* ATimer, int AMtab, int AMtalo, TNewLineEvent AOnl, TNewCharEvent AOnc, System::Classes::TNotifyEvent Ot, TTerminateProcessEvent AOtp, int Ap, bool Aito, System::Classes::TStrings* AEnv, TCharDecoding AOnCharDecoding, TCharEncoding AOnCharEncoding);
	__fastcall virtual ~TDosThread();
	HIDESBASE void __fastcall Terminate();
	__property TInputLines* InputLines = {read=FInputLines};
};


class PASCALIMPLEMENTATION TDosCommand : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	System::UnicodeString FCommandLine;
	System::UnicodeString FCurrentDir;
	System::Classes::TStrings* FEnvironment;
	unsigned FExitCode;
	bool FInputToOutput;
	System::Classes::TStringList* FLines;
	int FMaxTimeAfterBeginning;
	int FMaxTimeAfterLastOutput;
	TCharDecoding FOnCharDecoding;
	TCharEncoding FOnCharEncoding;
	TErrorEvent FonExecuteError;
	TNewCharEvent FOnNewChar;
	TNewLineEvent FOnNewLine;
	System::Classes::TNotifyEvent FOnTerminated;
	TTerminateProcessEvent FOnTerminateProcess;
	System::Classes::TStrings* FOutputLines;
	int FPriority;
	TDosThread* FThread;
	TProcessTimer* FTimer;
	TEndStatus __fastcall get_EndStatus();
	bool __fastcall get_IsRunning();
	void __fastcall set_CharDecoding(const TCharDecoding AValue);
	void __fastcall set_CharEncoding(const TCharEncoding AValue);
	
private:
	int FEndStatus;
	_PROCESS_INFORMATION FProcessInformation;
	
protected:
	virtual System::UnicodeString __fastcall DoCharDecoding(System::TObject* ASender, System::Classes::TStream* ABuf);
	virtual void __fastcall DoCharEncoding(System::TObject* ASender, const System::UnicodeString AChars, System::Classes::TStream* AOutBuf);
	void __fastcall ThreadTerminated(System::TObject* ASender);
	
public:
	__fastcall virtual TDosCommand(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TDosCommand();
	void __fastcall Execute();
	void __fastcall SendLine(const System::UnicodeString AValue, bool AEol);
	void __fastcall Stop();
	__property TEndStatus EndStatus = {read=get_EndStatus, nodefault};
	__property unsigned ExitCode = {read=FExitCode, nodefault};
	__property bool IsRunning = {read=get_IsRunning, nodefault};
	__property System::Classes::TStringList* Lines = {read=FLines};
	__property System::Classes::TStrings* OutputLines = {read=FOutputLines, write=FOutputLines};
	__property int Priority = {read=FPriority, write=FPriority, nodefault};
	__property _PROCESS_INFORMATION ProcessInformation = {read=FProcessInformation};
	
__published:
	__property System::UnicodeString CommandLine = {read=FCommandLine, write=FCommandLine};
	__property System::UnicodeString CurrentDir = {read=FCurrentDir, write=FCurrentDir};
	__property System::Classes::TStrings* Environment = {read=FEnvironment};
	__property bool InputToOutput = {read=FInputToOutput, write=FInputToOutput, nodefault};
	__property int MaxTimeAfterBeginning = {read=FMaxTimeAfterBeginning, write=FMaxTimeAfterBeginning, nodefault};
	__property int MaxTimeAfterLastOutput = {read=FMaxTimeAfterLastOutput, write=FMaxTimeAfterLastOutput, nodefault};
	__property TCharDecoding OnCharDecoding = {read=FOnCharDecoding, write=set_CharDecoding};
	__property TCharEncoding OnCharEncoding = {read=FOnCharEncoding, write=set_CharEncoding};
	__property TErrorEvent OnExecuteError = {read=FonExecuteError, write=FonExecuteError};
	__property TNewCharEvent OnNewChar = {read=FOnNewChar, write=FOnNewChar};
	__property TNewLineEvent OnNewLine = {read=FOnNewLine, write=FOnNewLine};
	__property System::Classes::TNotifyEvent OnTerminated = {read=FOnTerminated, write=FOnTerminated};
	__property TTerminateProcessEvent OnTerminateProcess = {read=FOnTerminateProcess, write=FOnTerminateProcess};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Doscommand */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DOSCOMMAND)
using namespace Doscommand;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DoscommandHPP
