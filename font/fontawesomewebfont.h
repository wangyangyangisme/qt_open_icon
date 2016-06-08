#ifndef FONTAWESOMEWEBFONT_H
#define FONTAWESOMEWEBFONT_H

#include "abstractfont.h"

class FontawesomeWebfont : public AbstractFont
{
public:
    enum ICON_INDEX{
        ICON_LOCK = 0xf023,
        ICON_UNLOCK = 0xf09c,
        BATTERY_0 = 0xf244,
        BATTERY_1 = 0xf243,
        BATTERY_2 = 0xf242,
        BATTERY_3 = 0xf241,
        BATTERY_4 = 0xf240
    };
    explicit FontawesomeWebfont();
};

#endif // FONTAWESOMEWEBFONT_H
