#include <stdio.h>
#include <stdlib.h>
#include "include/lua.h"
#include "include/lualib.h"
#include "include/lauxlib.h"

#include "luadebug.h"

int main () {
    const char *fn = "double.lua";
    lua_State *lua = luaL_newstate();
    luaL_openlibs(lua);
    if ( luaL_dofile(lua, fn) != 0 ) {
        printf("failed execute %s\n", fn);
        exit(1);
    }

    lua_getglobal(lua, "double");
    lua_newtable(lua);

    printStack(lua);

    int arr[] = { 3, 6, 9, 12, 15 };
    int i;
    for ( i = 0; i < 5; i++ ) {
        lua_pushnumber(lua, arr[i]);
        printStack(lua);
        lua_rawseti(lua, 2, i + 1);

        printStack(lua);
    }

    lua_call(lua, 1, 1);

    int value;
    for( i = 0; i < 5; i++ ) {
        lua_rawgeti(lua, -1, i + 1);
        value = lua_tonumber(lua, -1);

        printStack(lua);

        lua_pop(lua, 1);

        printf("%d: %d\n", i, value);
    }

    lua_close(lua);

    return 0;
}
