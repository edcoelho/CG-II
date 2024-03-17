CXXFLAGS := -pedantic-errors -Wall
LDLIBS := -lGL -lGLEW -lglut

# Diretórios importantes.
SRC_DIR := src/
INCLUDE_DIR := include/
BUILD_DIR := build/

# Arquivo main padrão.
MAIN := $(addprefix $(SRC_DIR), main.cpp)
# Arquivo .o relativo ao arquivo definido como main.
MAIN_OBJ := $(patsubst %.cpp, %, $(notdir $(MAIN)))
MAIN_OBJ := $(addprefix $(BUILD_DIR), $(MAIN_OBJ)).o

# Lista de arquivos .cpp
CPP_FILES := $(shell find $(SRC_DIR) -name "*.cpp")

# Lista de arquivos .hpp
HPP_FILES := $(shell find $(INCLUDE_DIR) -name "*.hpp")

# Lista de arquivos .o
OBJ_FILES := $(patsubst $(SRC_DIR)%.cpp, $(BUILD_DIR)%.o, $(CPP_FILES))
# Gambiarra para tirar da lista os arquivos main.
# Tira da lista os arquivos .o que não tem .hpp correspondente.
OBJ_FILES := $(filter $(patsubst $(INCLUDE_DIR)%.hpp, $(BUILD_DIR)%.o, $(HPP_FILES)), $(OBJ_FILES))

# Lista de headers sem implementação.
HEADERSONLY := $(filter-out $(patsubst $(SRC_DIR)%.cpp, $(INCLUDE_DIR)%.hpp, $(CPP_FILES)), $(HPP_FILES))

# Indicando para o make quais targets não estão associados com arquivos.
.PHONY: main clean debug

# Target padrão (tem que ser o primeiro definido).
ALL: $(BUILD_DIR) main

# Target para gerar executável para debugging.
debug: CXXFLAGS += -g
debug: clean ALL

# Target para ligação.
main: $(MAIN_OBJ) $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) $(MAIN_OBJ) -o main $(LDLIBS)

# Target para compilação do arquivo main.
$(MAIN_OBJ): $(MAIN) $(HEADERSONLY)
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I $(INCLUDE_DIR)

# Target para compilação dos arquivos outros arquivos .cpp
$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp $(INCLUDE_DIR)%.hpp $(HEADERSONLY)
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I $(INCLUDE_DIR)

# Target para criar o diretório build.
$(BUILD_DIR):
ifeq ($(wildcard $(BUILD_DIR)),)
    $(shell mkdir $(BUILD_DIR))
    $(shell find $(INCLUDE_DIR) -type d -exec mkdir -p "$(BUILD_DIR){}" \;)
    $(shell mv $(BUILD_DIR)$(INCLUDE_DIR)* $(BUILD_DIR) 2>/dev/null ; true) # "2>/dev/null" faz um possível erro do mv ser ignorado
    $(shell rm -r $(BUILD_DIR)$(INCLUDE_DIR))
endif

# Target para apagar objetos e executável.
clean:
	rm -rf $(BUILD_DIR) *.o main
	clear