# app makefile
MY_TARGETDIR := $(APPS_BUILD_DIR)/vmtest
MY_SRCDIR := $(APPS_DIR)/vmtest
MY_TARGET :=  $(MY_TARGETDIR)/vmtest
ifeq ($(call FINDINLIST,$(MY_TARGET),$(ALL)),1)

MY_SRCS := \
	main.c

MY_INCLUDES := $(STDINCLUDE)
MY_CFLAGS := $(USER_CFLAGS)
MY_LIBS := -lc -lnewos -lsupc++
MY_LIBPATHS :=
MY_DEPS :=
MY_GLUE := $(APPSGLUE)

include templates/app.mk

endif

