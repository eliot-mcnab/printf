# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 09:54:21 by emcnab            #+#    #+#              #
#    Updated: 2022/12/05 19:58:27 by emcnab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==============================================================================
#                                      DISPLAY
# ==============================================================================

# colors
BLACK   = \033[0;30m
GRAY    = \033[1;30m
RED     = \033[0;31m
LRED    = \033[1;31m
GREEN   = \033[0;32m
LGREEN  = \033[1;32m
ORANGE  = \033[0;33m
YELLOW  = \033[1;33m
BLUE    = \033[0;34m
LBLUE   = \033[1;34m
PURPLE  = \033[0;35m
LPURPLE = \033[1;35m
CYAN    = \033[0;36m
LCYAN   = \033[1;36m
LGRAY   = \033[0;37m
WHITE   = \033[1;37m

# ==============================================================================
#                                    COMPILATION
# ==============================================================================

# c source files
CDIR  = srcs/
SRCS   = buffadd.c		buffclose.c		buffinit.c		bufflush.c    \
         buffull.c		data.c			format.c		modifiers.c   \
		 parse.c		ft_printf.c		ft_printchar.c	ft_printstr.c \

CFILES += $(foreach file, $(SRCS), $(CDIR)$(file))

# object files
ODIR   = objs/
OFILES = $(patsubst $(CDIR)%.c, $(ODIR)%.o, $(CFILES))

# dependency files used for hearder awareness
DEPDIR = deps/
DFILES = $(patsubst $(CDIR)%.c, $(DEPDIR)%.d, $(CFILES))

# header info
HDIR   = includes/

# libft  info
LIBDIR = libft/
LIBGIT = https://github.com/eliot-mcnab/libft.git

# compilation options
CC     = cc
OPT    = 0
CMODE  = debug deps fsanitize
DFLAGS = $(foreach directory, $(HDIR), -I$(directory)) -M -MP -MM
CFLAGS = -Wall -Wextra -Werror

ifneq ($(filter debug, $(CMODE)),)
	CFLAGS += -g
endif
ifneq ($(filter fsanitize, $(CMODE)),)
	CFLAGS += -fsanitize=address
endif
ifneq ($(filter hard, $(CMODE)),)
	CFLAGS += -Weverything
endif
ifneq ($(filter opt, $(CMODE)),)
	CFLAGS += -O$(OPT)
endif

# archive options
ADIR   = archives/
AR     = ar
AFLAGS = -rcs

#binary name
BINARY = libprintf.a

# test file
TEST   = test.c

# ==============================================================================
#                                       RULES
# ==============================================================================

# by default, builds binary
all: libft $(BINARY)

# builds libft library
libft: $(LIBDIR)
	@(cd ./libft/ && make)
	@cp ./libft/libft.a $(ADIR)

# for binary to be built, all object files must have been compiled into the
# object directory
$(BINARY): $(ODIR) $(DEPDIR) $(OFILES)
	@$(AR) $(AFLAGS) $(ADIR)$@ $(OFILES)
	@echo "${LGREEN}${LGRAY}"
	@echo "${LGREEN} ${WHITE}${BINARY} ${LGREEN}built successfully!${LGRAY}"
	@$(AR) $(AFLAGS) -M <libftprintf.mri
	@echo "${LGREEN} ${WHITE}libftprintf.a ${LGREEN}built successfully!${LGRAY}"

# if a required directory does not exist, creates it
%/:
	@mkdir $@
	@echo "${LGREEN} created directory ${@}${LGRAY}"

# for any .o file to be compiled, the corresponding .c file must exist
$(ODIR)%.o: $(CDIR)%.c $(DEP)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "${GREEN}|${LGRAY}"
	@echo "${LGREEN} ${LGRAY}${@} ${GREEN}built successfully!${LGRAY}"

$(DEPDIR)%.d: $(CDIR)%.c
	@$(CC) $(DFLAGS) -MF $@ -MT $(patsubst $(CDIR)%.c, $(ODIR)%.o, $<) $<
	@echo "${ORANGE}|${LGRAY}"
	@echo "${ORANGE} ${LGRAY}${@} ${ORANGE}dependency generated!${LGRAY}"

# removes all object files
oclean:
	@rm -f $(OFILES)
	@echo "${RED} removed all object files${LGRAY}"

# removes all dependency files
dclean:
	@rm -f $(DFILES)
	@echo "${RED} removed all dependency files${LGRAY}"

# removes all object and dependency files
clean: oclean dclean
	@rm -f test

# removes all object files and the binary
fclean: clean
	@rm -f $(BINARY) ./libft.a ./libftprintf.a
	@echo "${RED}|${LGRAY}"
	@echo "${LRED} removed ${WHITE}${BINARY}${LGRAY}"

# removes all compiled files and re-compiles the binary
re: fclean
	@make all

# to update libft, libft must have been cloned
update: $(LIBDIR)
	@echo "${LPURPLE}  updating ${WHITE}libft ${LPURPLE}...${LGRAY}"
	@(cd libft/ && git pull)
	@cp libft/libft.h includes/

# clones libft into the repo
$(LIBDIR): 
	@echo "${LPURPLE}  cloning ${WHITE}libft ${LPURPLE}...${LGRAY}"
	@echo "${LPURPLE}|${LGRAY}"
	@git clone $(LIBGIT)

# displays debug info
debug:
	@echo $(CFILES)
	@echo $(OFILES)
	@echo $(DFILES)

#builds and runs test file
test: all
	@$(CC) $(CFLAGS) -o test $(TEST) ./libftprintf.a
	@chmod u+x ./test 
	@echo "${LRED}Running tests...${LGRAY}"
	@./test

ifneq ($(filter deps, $(CMODE)),)
-include $(DFILES)
endif

.PHONY: all libft oclean dclean clean fclean re update debug test
