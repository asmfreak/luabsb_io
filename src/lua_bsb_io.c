#define LUA_LIB
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <luaconf.h>
#include "bsb_fastio.h"

static int lua_bsb_setup(lua_State *L){
	lua_pushnumber(L, bsb_setup());
	return 1;
}

static int lua_bsb_set(lua_State *L){
	lua_Integer gpio = luaL_checkinteger(L, 1);
	lua_Integer val  = luaL_checkinteger(L, 2);
	//return luaL_error(L, "gpio is %d", gpio);
	if(val > 1 || val < 0)
	    return luaL_error(L,"val is invalid: %d",val);
	bsb_set(gpio, val);
	return 0;
}

static int lua_bsb_read(lua_State *L){
	lua_pushnumber(L, bsb_read(luaL_checkinteger(L,1)));
	return 1;
}

static int lua_bsb_direction(lua_State *L){
	lua_Integer gpio = luaL_checkinteger(L, 1); 
	lua_Integer dir  = luaL_checkinteger(L, 2);
	bsb_direction(gpio, dir);
	return 0;
}

static const luaL_Reg bsb_iolib[] = {
	{"setup", 	lua_bsb_setup},
	{"set",		lua_bsb_set},
	{"read",	lua_bsb_read},
	{"direction",	lua_bsb_direction},
	{"INPUT",	NULL},
	{"OUTPUT",	NULL},
	{"HIGH",	NULL},
	{"LOW",		NULL},
	{"ON",		NULL},
	{"OFF",		NULL},
};

#define lps_field(name,val) lua_pushnumber(L, val);lua_setfield(L, -2, name)

LUALIB_API int luaopen_bsb (lua_State *L){
	luaL_register(L, "bsb", bsb_iolib);
	lps_field("INPUT",	0);
	lps_field("OUTPUT",	1);
	lps_field("ON",		1);
	lps_field("OFF",	0);
	lps_field("HIGH",	1);
	lps_field("LOW",	0);
	return 1;
}
