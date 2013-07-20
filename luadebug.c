#include "luadebug.h"

/*
   http://marupeke296.com/LUA_No2_Begin.html 
*/

// スタックを見る関数
void printStack(lua_State *L) {
#ifndef DEBUG
    return;
#endif
    // スタック数を取得
    const int num = lua_gettop(L);
    if (num == 0) {
        printf("No stack.\n");
        return;
    }

    printf("-----------------------------\n");

    int i;
    for (i = num; i >= 1; i--) {
        printf("%03d(%04d): ", i, -num + i - 1);
        int type = lua_type(L, i);
        switch(type) {
        case LUA_TNIL:
            printf("NIL\n");
            break;
        case LUA_TBOOLEAN:
            printf("BOOLEAN %s\n", lua_toboolean(L, i) ? "true" : "false");
            break;
        case LUA_TLIGHTUSERDATA:
            printf("LIGHTUSERDATA\n");
            break;
        case LUA_TNUMBER:
            printf("NUMBER %f\n", lua_tonumber(L, i));
            break;
        case LUA_TSTRING:
            printf("STRING %s\n", lua_tostring(L, i));
            break;
        case LUA_TTABLE:
            printf("TABLE\n");
            break;
        case LUA_TFUNCTION:
            printf("FUNCTION\n");
            break;
        case LUA_TUSERDATA:
            printf("USERDATA\n");
            break;
        case LUA_TTHREAD:
            printf("THREAD\n");
            break;
        }
    }
    printf("-----------------------------\n\n");
}
