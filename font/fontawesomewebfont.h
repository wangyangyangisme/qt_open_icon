#ifndef FONTAWESOMEWEBFONT_H
#define FONTAWESOMEWEBFONT_H

#include "abstractfont.h"

class FontawesomeWebfont : public AbstractFont
{
public:
    enum ICON_INDEX{
        ICON_WIFI = 0xf1eb,
        ICON_LOCK = 0xf023,
        ICON_UNLOCK = 0xf09c,
    };
    explicit FontawesomeWebfont();
};

#endif // FONTAWESOMEWEBFONT_H
