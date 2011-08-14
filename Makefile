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
INCLUDES  =   include/
CFLAGS    =   -W -Wall -O3 -I $(INCLUDES)
CC        =   gcc
RM        =   rm -f
AR        =   ar r
RANLIB    =   ranlib
SRCS      =   $(shell find src -name "*.c")
OBJS      =   $(SRCS:.c=.o)
SRCS_UNIT =   $(shell find unit -name "*.c")
OBJS_UNIT =   $(SRCS_UNIT:.c=.o)
UNIT_NAME =   unit_tests

target debug:CFLAGS  =    -W -Wall -g3 -I $(INCLUDES)
target unit :CFLAGS  =    -W -Wall -g3 -I $(INCLUDES)

$(NAME)   :   $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

all       :   $(NAME)

clean     :
	$(RM) $(OBJS) $(OBJS_UNIT)

fclean    :   clean
	$(RM) $(NAME) $(UNIT_NAME)

re        :   fclean all

debug     :   re

unit      :   re $(OBJS_UNIT)
	$(CC) -o $(UNIT_NAME) $(OBJS) $(OBJS_UNIT)
	./$(UNIT_NAME)

.PHONY    : unit debug re fclean clean all