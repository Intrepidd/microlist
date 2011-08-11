# Copyright 2011 Adrien Siami

#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at

#       http://www.apache.org/licenses/LICENSE-2.0

#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.

NAME      =   microlist.a
CFLAGS    =   -W -Wall -O3
CC        =   gcc
RM        =   rm -f
AR        =   ar r
RANLIB    =   ranlib
SRCS      =   $(shell find -name "*.c")
OBJS      =   $(SRCS:.c=.o)
INCLUDES  =   includes/

$(NAME)   :   $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

all       :   $(NAME)

clean     :
	$(RM) $(OBJS)

fclean    :   clean
	$(RM) $(NAME)

re        :   fclean all

target debug:
CFLAGS  =    -W -Wall -g3

debug     :   re
