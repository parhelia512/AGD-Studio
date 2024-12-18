//---------------------------------------------------------------------------
#ifndef BitmapGraphicsBufferH
#define BitmapGraphicsBufferH
//---------------------------------------------------------------------------
#include "GraphicsBuffer.h"
#include "Messaging/Event.h"
//---------------------------------------------------------------------------
namespace Visuals
{
//---------------------------------------------------------------------------
// A paletted bitmap buffer has pixels defined as a color value stored in a byte.
// This buffer supports 1 bit (monochrome) to 2, 4 or 8 bits per colour.
//---------------------------------------------------------------------------
class BitmapGraphicsBuffer : public GraphicsBuffer
{
private:
    Registrar           m_Registrar;
    void    __fastcall  OnEvent(const Event& event);

public:
            __fastcall  BitmapGraphicsBuffer(unsigned int width, unsigned int height, const GraphicsMode& mode);
            __fastcall ~BitmapGraphicsBuffer();

    void    __fastcall  SetPixel(unsigned int X, unsigned int Y, bool set);
    void    __fastcall  GetColor(unsigned int X, unsigned int Y, unsigned char colorIndex = 0);
    void    __fastcall  Render() const;
    void    __fastcall  Set(const String& data);
};
//---------------------------------------------------------------------------
} // Visuals namespace
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
