//---------------------------------------------------------------------------
#include <AgdStudio.pch.h>
#pragma hdrstop
#include "Event.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
template class OnChange<int>;
template class OnChange<float>;
template class OnChange<String>;
template class OnChange<bool>;
template class DocumentChange<String>;
//---------------------------------------------------------------------------
