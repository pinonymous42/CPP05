NAME        :=  Form_up,_maggots!
CC			:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98
INCLUDE		:=	-Iincludes
VPATH		:=	srcs
SRCS		:=	main.cpp Bureaucrat.cpp Form.cpp
OBJSDIR		:=	objs
OBJS		:=	$(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))
RM			:=	rm -rf

all: $(NAME)

$(NAME): $(OBJSDIR) $(OBJS)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJSDIR)/%.o: %.cpp
	$(CC) $(INCLUDE) $(CXXFLAGS) -o $@ -c $<

objs:
	mkdir -p objs

clean:
	$(RM) $(OBJSDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
