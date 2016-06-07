#ifndef MUIFONT_H
#define MUIFONT_H

#include "abstractfont.h"

class MuiFont : public AbstractFont
{
public:
    //随用随加
    enum ICON_INDEX{
        ICON_WEINXIN = 0xe261,
        ICON_PENGYOUQUAN = 0xe262,
    };
    explicit MuiFont();
};

#endif // MUIFONT_H
