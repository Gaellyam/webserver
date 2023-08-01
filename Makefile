# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 07:23:39 by sdi-lega          #+#    #+#              #
#    Updated: 2023/08/01 21:58:45 by sdi-lega         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = webserv

SRCSDIR = sources/
 
CLASSES = Socket

SRCS = ${addsuffix .cpp, ${addprefix ${SRCSDIR}, main ${foreach classe, ${CLASSES}, ${classe}/${classe}}}}

OBJSDIR = objects/

SILENT = @
DEBUG =
OBJS = ${addsuffix .o, ${addprefix ${OBJSDIR}, main ${foreach classe, ${CLASSES}, ${classe}/${classe}}}}

CC = c++

FLAGS = -Wall -Wextra -Werror -g -std=c++98 ${addprefix -I${SRCSDIR},${CLASSES}} $(DEBUG)

all : ${OBJSDIR} ${NAME}
		${SILENT}echo All instructions done!

re : fclean all

${NAME} : ${OBJS}
		${SILENT}echo "\033[KCreating \"$@\" executable.\033[1A"
		${SILENT}${CC} ${FLAGS} ${OBJS} -o ${NAME}
		${SILENT}echo "\033[K\033[32;1;4m\"$@\" executable created!.\033[0m"

${OBJSDIR}%.o : ${SRCSDIR}%.cpp
		${SILENT}echo "\033[K\033[32;1;4mCreating \"${notdir $*}\" object file.\033[1A\033[0m"
		${SILENT}${CC} ${FLAGS} -c $^ -o $@
		${SILENT}echo "\033[K\"${notdir $*}\"\033[15Gobject file \033[32;1;4mcreated\033[0m."
		
${OBJSDIR} : 
		${SILENT}echo "\033[K\033[32;1;4mCreating objects folders.\033[1A\033[0m"
		${SILENT}mkdir -p ${addprefix ${OBJSDIR}, ${CLASSES}}
		${SILENT}echo "\033[KObjects folders \033[32;1;4mcreated\033[0m."
		
clean :
	@for file in $(OBJS); do \
		if [ -f $$file ]; then \
			echo "\033[K\033[31;1;4mDeleting objects.\033[1A\033[0m"; \
			rm -rf ${OBJS};\
			echo "\033[KObjects \033[31;1;4mdeleted\033[0m.";\
			found=1; \
			break; \
		fi; \
	done; \
	if [ -z "$$found" ]; then \
		echo "No objects files found to delete."; \
	fi;

fclean : clean
	@for file in $(NAME); do \
		if [ -f $$file ]; then \
			echo "\033[K\033[31;1;4mDeleting executable and objects folders.\033[1A\033[0m"; \
			rm -rf ${NAME} ${OBJSDIR}; \
			echo "\033[KExecutable and objects folders \033[31;1;4mdeleted\033[0m."; \
			found=1; \
			break; \
		fi; \
	done; \
	if [ -z "$$found" ]; then \
		echo "No executables files found to delete."; \
	fi;

debug : DEBUG = -DDEBUG=1
debug : re

.PHONY : all re debug clean fclean
