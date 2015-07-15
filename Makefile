include $(TOPDIR)/rules.mk

PKG_NAME:=luabsb_io
PKG_VERSION:=0.0.2
PKG_RELEASE:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)
include $(INCLUDE_DIR)/package.mk

define Package/luabsb_io
    SUBMENU:=Lua
    SECTION:=lang
    CATEGORY:=Languages
    DEFAULT:=n
    TITLE:=BlackSwift GPIO Lua module
    URL:=http://black-swift.com
    DEPENDS:=+libstdcpp +lua
    PKG_BUILD_DEPENDS:=+lua/host
endef

define Package/luabsb_io/description
    BlackSwift GPIO Lua module
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Configure
	$(call Build/Configure/Default,--with-linux-headers=$(LINUX_DIR))
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) INCDIR="$(TARGET_CPPFLAGS)" \
		LIBDIR="$(TARGET_LDFLAGS)" \
		CC="$(TARGET_CC) $(TARGET_CFLAGS) -std=gnu99" \
		LD="$(TARGET_CROSS)ld -shared" \
		LUACPATH="$(PKG_INSTALL_DIR)/usr/lib/lua" \
		LUAPATH="$(PKG_INSTALL_DIR)/usr/lib/lua" \
		bsb.so
endef


define Package/luabsb_io/install
	$(INSTALL_DIR) $(1)/usr/lib/lua
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/bsb.so $(1)/usr/lib/lua/
endef

$(eval $(call BuildPackage,luabsb_io))

