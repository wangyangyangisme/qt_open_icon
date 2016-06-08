#include "batterybutton.h"

/**
 * @brief BatteryButton::BatteryButton
 * @param power 代表当前电量情况
 * @param curStateStyle 对应当前电量情况的样式
 */
BatteryButton::BatteryButton(POWER power, const QString curStateStyle):
    BaseButton(FontawesomeWebfont(), power, 200, 100, curStateStyle)
{
}

void BatteryButton::changePower(POWER power)
{
    switch (power) {
    case EMPTY:
    case QUARTER:
        setStyleSheet(EMPTY_BATTERY_STYLE);
        break;
    case HALF:
        setStyleSheet(HALF_BATTERY_STYLE);
        break;
    case THREE_QUARTER:
    case FULL:
        setStyleSheet(FULL_BATTERY_STYLE);
        break;
    default:
        break;
    }
    iconhelp::setIcon(this,power);
}

void BatteryButton::releaseSlot()
{
    curIndex = (++curIndex) % 5;  //电池有5种状态
    switch (curIndex) {
    case 0:
        changePower(EMPTY);
        break;
    case 1:
        changePower(QUARTER);
        break;
    case 2:
        changePower(HALF);
        break;
    case 3:
        changePower(THREE_QUARTER);
        break;
    case 4:
        changePower(FULL);
        break;
    default:
        break;
    }
}
