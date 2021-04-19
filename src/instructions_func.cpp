/** @file instructions_func.cpp
 *  @brief Módulo que contém todas as instruções da JVM.
 *  @bug No know bugs.
 */
#include "interpreter.hpp"
#include "instructions_func.hpp"

/**
 * @brief ??? 
 * 
 * 
 */
namespace patch {
  template <typename T> string to_string(const T& n) {
    std::ostringstream stm;
    stm << n;
    return stm.str();
  }
}

/*************************** CONSTANTS ***************************/
/** 
 * @brief Não faz nada, só incrementa pc.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void nop(Frame *curr_frame) {
  curr_frame->pc++;
}

/** @brief Empurra o valor NULL na pilha de operandos
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void aconst_null(Frame* curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_EMPTY;
    curr_frame->push_operand(op);
    curr_frame->pc++;
}

/** @brief Empurra int na pilha de operandos
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void iconst_m1(Frame* curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_INT;
    op->type_int = -1;
    curr_frame->push_operand(op);
    curr_frame->pc++;
}

/** @brief Empurra int na pilha de operandos
 * @param *curr_frame ponteiro para o frame atualiconst_2
 * @return void
 */
void iconst_0(Frame* curr_frame) {
  Operand *op = (Operand*)malloc(sizeof(Operand));
  op->tag = CONSTANT_INT;
  op->type_int = 0;
  curr_frame->push_operand(op);
  curr_frame->pc++;

  if (DEBUG) cout << "iconst_0\n";
}

/** @brief ...
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void iconst_1(Frame* curr_frame) {
  if (DEBUG) cout << "\n----------iconst_1----------\n";

    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_INT;
    op->type_int = 1;
    curr_frame->push_operand(op);

    curr_frame->pc++;
}

/** @brief Empurra int na pilha de operandos
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void iconst_2(Frame* curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_INT;
    op->type_int = 2;
    curr_frame->push_operand(op);
    curr_frame->pc++;

    if (DEBUG) cout << "iconst_2\n";
}

/** @brief Empurra int na pilha de operandos
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void iconst_3(Frame* curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_INT;
    op->type_int = 3;
    curr_frame->push_operand(op);
    curr_frame->pc++;

    if (DEBUG) cout << "iconst_3\n";
}

/** @brief Empurra int na pilha de operandos
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void iconst_4(Frame* curr_frame) {
  Operand *op = (Operand*)malloc(sizeof(Operand));
  op->tag = CONSTANT_INT;
  op->type_int = 4;
  curr_frame->push_operand(op);
  curr_frame->pc++;

  if (DEBUG) cout << "iconst_4\n";
}

/** @brief Empurra int na pilha de operandos
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void iconst_5(Frame* curr_frame) {
  Operand *op = (Operand*)malloc(sizeof(Operand));
  op->tag = CONSTANT_INT;
  op->type_int = 5;
  curr_frame->push_operand(op);
  curr_frame->pc++;

  if (DEBUG) cout << "iconst_5\n";
}

/**
 * @brief Empilha a constante long 0 na pilha de opreandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lconst_0(Frame *curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_LONG;
    op->type_long = 0;
    curr_frame->operand_stack.push(op);
    curr_frame->pc++;
}

/**
 * @brief Empilha a constante long 1 na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lconst_1(Frame *curr_frame) {
  Operand *op = (Operand*)malloc(sizeof(Operand));
  op->tag = CONSTANT_LONG;
  op->type_long = 1;
  curr_frame->push_operand(op);
  curr_frame->pc++;

  if (DEBUG) cout << "lconst_1\n";
}

/**
 * @brief Empilha a constante float 0 na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fconst_0(Frame *curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_FLOAT;
    op->type_long = 0.0;
    curr_frame->operand_stack.push(op);
    curr_frame->pc++;
}

/**
 * @brief Empilha a constante float 1 na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fconst_1(Frame *curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_FLOAT;
    op->type_long = 1.0;
    curr_frame->operand_stack.push(op);
    curr_frame->pc++;

    if (DEBUG) cout << "fconst_1\n";
}

/**
 * @brief Empilha a constante float 0 na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fconst_2(Frame *curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_FLOAT;
    op->type_long = 2.0;
    curr_frame->operand_stack.push(op);
    curr_frame->pc++;
}

/**
 * @brief Empilha a constante double 0 na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dconst_0(Frame *curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_DOUBLE;

    op->type_double = 0.0;
    curr_frame->operand_stack.push(op);
    curr_frame->pc++;
}

/**
 * @brief Empilha a constante double 1 na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dconst_1(Frame *curr_frame) {
  Operand *op = (Operand*)malloc(sizeof(Operand));
  op->tag = CONSTANT_DOUBLE;

  op->type_double = 1.0;
  curr_frame->operand_stack.push(op);
  curr_frame->pc++;

  if (DEBUG) cout << "dconst_1\n";
}

/**
 * @brief Empilha int composto por byte de argumento na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void bipush(Frame *curr_frame) {
  if (DEBUG) cout << "\n----------bipush----------\n";

  curr_frame->pc++;

  Operand *op = (Operand*)malloc(sizeof(Operand));
  u1 byte = curr_frame->method_code->code[curr_frame->pc++];
  if (DEBUG) cout << "bipush byte " << byte << "\n";

  op->tag = CONSTANT_INT;
  op->type_int = (int8_t) byte;
  curr_frame->operand_stack.push(op);

}

/**
 * @brief Empilha int composto por byte de argumento na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void sipush(Frame *curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    u1 byte = curr_frame->method_code->code[curr_frame->pc++];
    u1 byte2 = curr_frame->method_code->code[curr_frame->pc++];
    op->tag = CONSTANT_INT;
    op->type_int = (byte<<8)|byte2;
    curr_frame->operand_stack.push(op);

}

/** @brief Coloca na pilha de operandos uma constante do tamanho de uma word.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void ldc(Frame *curr_frame) {
  if (DEBUG) cout << "\n----------ldc----------\n";

  curr_frame->pc++;
  Operand *op = (Operand*) malloc(sizeof(Operand));

  u1 index = curr_frame->method_code->code[curr_frame->pc++];
  if (DEBUG) cout << "ldc index: " << (int) index << "\n";

  Cp_Info &cp_info = curr_frame->cp_reference[((int)index)];
  op->tag = cp_info.tag;
  if (DEBUG) cout << "op->tag: " << (int) op->tag << "\n";

  switch (op->tag) {
    case CONSTANT_INT:
      op->type_int = cp_info.Integer.bytes;
      break;
    case CONSTANT_FLOAT:
      op->type_float = (float) cp_info.Float.bytes;
      if (DEBUG) cout << "ldc value: " << (float) op->type_float << "\n";
      break;
    case CONSTANT_STRING: {
      if (DEBUG) printf("Magic Number: 0x%0X\n", curr_frame->class_file_ref->magic_number);
      // string string_utf8 = get_cp_info_utf8(*(curr_frame->class_file_ref), cp_info.String.string_index);

      string string_utf8 = get_utf8_constant_pool(curr_frame->cp_reference, cp_info.String.string_index);
      if (DEBUG) cout << "string_utf8: " << string_utf8 << "\n";

      op->type_string = new string(string_utf8); 
    }
      break;
    case CONSTANT_CLASS: // TODO
      break;
    default:
      // CONSTANT_METHOD_HANDLE
      // CONSTANT_METHOD_REF
      break;
  }

    curr_frame->push_operand(op);
}

/** @brief Dá push de uma word na pilha de operandos.
@param Frame *curr_frame ponteiro que aponta para o frame atual
@return void
*/
void ldc_w(Frame *curr_frame) {
    curr_frame->pc++;

    u1 index_1 = curr_frame->method_code->code[curr_frame->pc++];
    u1 index_2 = curr_frame->method_code->code[curr_frame->pc++];

    u2 index = (index_1 << 8) + index_2;

    Cp_Info *cp_info = curr_frame->cp_reference + (int)index;
    Operand* operands = nullptr;

    switch(cp_info->tag) {
        case CONSTANT_INT:
            operands = (Operand*)malloc(sizeof(Operand));
            operands->tag = CONSTANT_INT;
            operands->type_int = cp_info->Integer.bytes;
            break;
        case CONSTANT_FLOAT:
            operands = (Operand*)malloc(sizeof(Operand));
            operands->tag = CONSTANT_FLOAT;
            operands->type_float = cp_info->Float.bytes;
            break;
        case CONSTANT_CLASS:
            //TODO
            printf("TODO");
            break;
        case CONSTANT_STRING:{
            operands = (Operand*)malloc(sizeof(Operand));
            operands->tag = CONSTANT_STRING;
            string utf8_cp = get_utf8_constant_pool(curr_frame->cp_reference, cp_info->String.string_index);

            operands->type_string = new string(utf8_cp);
            break;
        }
        default:
            //TODO
            printf("TODO");
            break; //methodRef e methodHandle não implementados
    }

    curr_frame->push_operand(operands);

}

/** @brief Dá push em duas words na pilha de operandos.
 * @param *curr_frame ponteiro que aponta para o frame atual
 * @return void
 */
void ldc2_w(Frame *curr_frame) {
  if (DEBUG) cout << "\n----------ldc2_w----------\n";
  curr_frame->pc++;

  u1 index_1 = curr_frame->method_code->code[curr_frame->pc++];
  u1 index_2 = curr_frame->method_code->code[curr_frame->pc++];

  u2 index = (index_1 << 8) + index_2;

  if (DEBUG) cout << "ldc2_w index : " << (int)index << "\n";
  Cp_Info *cp_info = curr_frame->cp_reference + (int)index;
  Operand* operands;

  if (cp_info->tag == CONSTANT_DOUBLE) { // double
    operands = (Operand*)malloc(sizeof(Operand));
    operands->tag = CONSTANT_DOUBLE;
    operands->type_double = cp_info->Double.high_bytes;
    operands->type_double = (operands->type_double << 32) + cp_info->Double.low_bytes;

    if (DEBUG) {
      double double_v;
      memcpy(&double_v, &operands->type_double, sizeof(double));
      printf("double value: %.15lf\n", double_v);
    }
  } else { // long
    operands = (Operand*) malloc(sizeof(Operand));
    operands->tag = CONSTANT_LONG;

    long read_long_value;
    memcpy(&read_long_value, &(cp_info->Long.high_bytes),sizeof(long));
    memcpy(&read_long_value, &(cp_info->Long.low_bytes),sizeof(long));

    operands->type_long = read_long_value;
    if (DEBUG) cout << "long value: " << operands->type_double << "\n";
  }
  curr_frame->push_operand(operands);
}


/*************************** LOADS ***************************/

/**
 * @brief Pusha um inteiro, indicado por um indice, na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void iload(Frame *curr_frame) {
  curr_frame->pc++;

  u1 index = curr_frame->method_code->code[curr_frame->pc++];
  if (DEBUG) cout << "iload index " << (int)index << "\n";
  curr_frame->push_operand(curr_frame->local_variables_array.at((int)index));

  if (DEBUG) cout << "iload\n";
}

/**
 * @brief Empilha float indicado no indice index do array de variáveis locais
 *  na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lload(Frame *curr_frame) {
  curr_frame->pc++;

  int index = curr_frame->method_code->code[curr_frame->pc++];
  curr_frame->push_operand(curr_frame->local_variables_array[(int)index]);

  if (DEBUG) cout << "lload\n";
}

/**
 * @brief Empilha float indicado no indice 0 do array de variáveis locais na
 *  pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fload(Frame *curr_frame) {
  curr_frame->pc++;

  u1 index = curr_frame->method_code->code[curr_frame->pc++];
  if (DEBUG) cout << "fload index " << (int)index << "\n";
  curr_frame->push_operand(curr_frame->local_variables_array[(int)index]);

  if (DEBUG) cout << "fload\n";
}

/** @brief Dá push em um valor de preciso dupla de uma variável local para a
 *  pilha de operandos.
 * @param *curr_frame ponteiro que aponta para o frame atual
 * @return void
 */
void dload(Frame *curr_frame) {
  curr_frame->pc++;

  u1 index = curr_frame->method_code->code[curr_frame->pc++];
  if (DEBUG) cout << "dload index " << (int)index << "\n";
  curr_frame->push_operand(curr_frame->local_variables_array.at((int)index));

  if (DEBUG) cout << "dload\n";
}

/** @brief Coloca na pilha de operandos a variável da posição do pc no vetor de variáveis locais.
 * @param *curr_frame ponteiro que aponta para o frame atual
 * @return void
 */
void aload(Frame *curr_frame) {
  curr_frame->pc++;

  u1 index = curr_frame->method_code->code[curr_frame->pc++];
  curr_frame->push_operand(curr_frame->local_variables_array.at(index));
}

/**
 * @brief Pusha o inteiro do indice 0 na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void iload_0(Frame *curr_frame) {
    curr_frame->push_operand(curr_frame->local_variables_array.at(0));
    curr_frame->pc++;
}

/**
 * @brief Pusha o inteiro do indice 1 na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void iload_1(Frame *curr_frame) {
    curr_frame->push_operand(curr_frame->local_variables_array.at(1));
    curr_frame->pc++;

    if (DEBUG) cout << "iload_1\n";
}

/**
 * @brief Pusha o inteiro do indice 2 na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void iload_2(Frame *curr_frame) {
    curr_frame->push_operand(curr_frame->local_variables_array.at(2));
    curr_frame->pc++;

    if (DEBUG) cout << "iload_2\n";
}

/**
 * @brief Pusha o inteiro do indice 3 na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void iload_3(Frame *curr_frame) {
    curr_frame->push_operand(curr_frame->local_variables_array.at(3));
    curr_frame->pc++;

    if (DEBUG) cout << "iload_3\n";
}

/**
 * @brief Empilha long indicado no indice 0 do array de variáveis locais na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lload_0(Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[0]);
  curr_frame->pc++;
}

/**
 * @brief Empilha long indicado no indice 1 do array de variáveis locais na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lload_1(Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[1]);
  curr_frame->pc++;

  if (DEBUG) cout << "lload_1\n";
}

/**
 * @brief Empilha long indicado no indice 2 do array de variáveis locais na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lload_2(Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[2]);
  curr_frame->pc++;
}

/**
 * @brief Empilha long indicado no indice 3 do array de variáveis locais na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lload_3(Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[3]);
  curr_frame->pc++;
  if (DEBUG) cout << "lload_3\n";

}

/**
 * @brief Empilha float indicado no indice 0 do array de variáveis locais na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fload_0(Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[0]);
  curr_frame->pc++;
}

/**
 * @brief Empilha float indicado no indice 1 do array de variáveis locais na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fload_1  (Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[1]);
  curr_frame->pc++;

  if (DEBUG) cout << "float_1\n";
}

/**
 * @brief Empilha float indicado no indice 2 do array de variáveis locais na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fload_2 (Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[2]);
  curr_frame->pc++;

  if (DEBUG) cout << "float_2\n";
}

/**
 * @brief Empilha float indicado no indice 3 do array de variáveis locais na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fload_3  (Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[3]);
  curr_frame->pc++;
}

/**
 * @brief empilha double  indicado no indice 0 do array de variaveis locais na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dload_0(Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[0]);
  curr_frame->pc++;
}

/**
 * @brief empilha double  indicado no indice 1 do array de variaveis locais na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dload_1(Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[1]);
  curr_frame->pc++;

  if (DEBUG) cout << "dload_1\n";
}

/**
 * @brief empilha double  indicado no indice 2 do array de variaveis locais na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dload_2(Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[2]);
  curr_frame->pc++;
}

/**
 * @brief empilha double  indicado no indice 3 do array de variaveis locais na pilha de operandos
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dload_3(Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[3]);
  curr_frame->pc++;

  if (DEBUG) cout << "dload_3\n";
}

/** @brief Coloca na pilha de operandos a variável da posição 0 do vetor de
 *          variáveis locais.
 * @param *curr_frame ponteiro que aponta para o frame atual
 * @return void
 */
void aload_0(Frame *curr_frame) {
    curr_frame->pc++;
    curr_frame->push_operand(curr_frame->local_variables_array.at(0));
}

/** @brief Coloca na pilha de operandos a variável da posição 1 do vetor de
 *          variáveis locais.
 * @param *curr_frame ponteiro que aponta para o frame atual
 * @return void
 */
void aload_1(Frame *curr_frame) {
  curr_frame->pc++;
  curr_frame->push_operand(curr_frame->local_variables_array.at(1));

  if (DEBUG) cout << "aload_1\n";
}

/** @brief Coloca na pilha de operandos a variável da posição 2 do vetor de
 *          variáveis locais.
 * @param *curr_frame ponteiro que aponta para o frame atual
 * @return void
 */
void aload_2(Frame *curr_frame) {
    curr_frame->pc++;
    curr_frame->push_operand(curr_frame->local_variables_array.at(2));
}

/** @brief Coloca na pilha de operandos a variável da posição 3 do vetor de
 *          variáveis locais.
 * @param *curr_frame ponteiro que aponta para o frame atual
 * @return void
 */
void aload_3(Frame *curr_frame) {
    curr_frame->pc++;
    curr_frame->push_operand(curr_frame->local_variables_array.at(3));
}

/**
* @brief Coleta um inteiro do vetor de referência e coloca na pilha.
* @param *curr_frame ponteiro para o frame atual
* @return void
*/
void iaload(Frame *curr_frame) {
  Operand* index = curr_frame->pop_operand();
  Operand* array = curr_frame->pop_operand();

  if (DEBUG) cout << "array size : " << array->array_type->array->size()
                        << "\n";
  Operand* op = array->array_type->array->at(index->type_int);
  if (DEBUG) cout << "array index : " << (int)index->type_int << "\n";
  if (DEBUG)
     for (int j=0; (unsigned)j < array->array_type->array->size(); ++j) {
       int value = (array->array_type->array->at(j))->type_int;
       cout << "array item : " << value << "\n";
     }
  curr_frame->push_operand(op);

  curr_frame->pc++;
  if (DEBUG) cout << "iaload\n";
}

/**
* @brief Coleta um long do vetor de referência e coloca na pilha.
* @param *curr_frame ponteiro para o frame atual
* @return void
*/
void laload(Frame *curr_frame) {
  Operand* index = curr_frame->pop_operand();
  Operand* array = curr_frame->pop_operand();

  if (DEBUG) cout << "array size : " << array->array_type->array->size()
                        << "\n";
  Operand* op = array->array_type->array->at(index->type_int);
  if (DEBUG) cout << "array index : " << (int)index->type_int << "\n";
  if (DEBUG)
     for (int j=0; (unsigned)j < array->array_type->array->size(); ++j) {
       int value = (array->array_type->array->at(j))->type_long;
       cout << "array item : " << value << "\n";
     }
  curr_frame->push_operand(op);

  curr_frame->pc++;
  if (DEBUG) cout << "laload\n";
}

/**
* @brief Coleta um float do vetor de referência e coloca na pilha.
* @param *curr_frame ponteiro para o frame atual
* @return void
*/
void faload(Frame *curr_frame) {
  Operand* index = curr_frame->pop_operand();
  Operand* array = curr_frame->pop_operand();

  if (DEBUG) cout << "array size : " << array->array_type->array->size()
                        << "\n";
  Operand* op = array->array_type->array->at(index->type_int);

  if (DEBUG) cout << "array index : " << (int)index->type_int << "\n";
  if (DEBUG) cout << "array index value : " << op->type_float << "\n";
  if (DEBUG)
     for (int j=0; (unsigned)j < array->array_type->array->size(); ++j) {
       int value = (array->array_type->array->at(j))->type_float;
       cout << "array item : " << value << "\n";
     }
  curr_frame->push_operand(op);

  curr_frame->pc++;
  if (DEBUG) cout << "faload\n";
}

/**
* @brief Coleta um double do vetor de referência e coloca na pilha.
* @param *curr_frame ponteiro para o frame atual
* @return void
*/
void daload(Frame *curr_frame) {
  Operand* index = curr_frame->pop_operand();
  Operand* array = curr_frame->pop_operand();

  if (DEBUG) cout << "array size : " << array->array_type->array->size()
                        << "\n";
  Operand* op = array->array_type->array->at(index->type_int);
  if (DEBUG) cout << "array index : " << (int)index->type_int << "\n";
  if (DEBUG)
     for (int j=0; (unsigned)j < array->array_type->array->size(); ++j) {
       int value = (array->array_type->array->at(j))->type_double;
       cout << "array item : " << value << "\n";
     }
  curr_frame->push_operand(op);

  curr_frame->pc++;
  if (DEBUG) cout << "daload\n";
}

/**
* @brief Coleta um objeto do vetor de referência e coloca na pilha.
* @param *curr_frame ponteiro para o frame atual
* @return void
*/
void aaload(Frame *curr_frame) {
  Operand* index = curr_frame->pop_operand();
  Operand* array = curr_frame->pop_operand();

  if (DEBUG) cout << "array size : " << array->array_type->array->size()
                        << "\n";
  Operand* op = array->array_type->array->at(index->type_int);
  if (DEBUG) cout << "array index : " << (int)index->type_int << "\n";
  if (DEBUG)
     for (int j=0; (unsigned)j < array->array_type->array->size(); ++j)
       cout << "sub array size : " << (array->array_type->array->at(j))->array_type->array->size() << "\n";
  curr_frame->push_operand(op);

  curr_frame->pc++;
  if (DEBUG) cout << "aaload\n";
}

/**
* @brief Coleta um booleano do vetor de referência e coloca na pilha.
* @param *curr_frame ponteiro para o frame atual
* @return void
*/
void baload(Frame *curr_frame) {
  Operand* index = curr_frame->pop_operand();
  Operand* array = curr_frame->pop_operand();

  if (DEBUG) cout << "array size : " << array->array_type->array->size()
                        << "\n";
  Operand* op = array->array_type->array->at(index->type_int);
  if (DEBUG) cout << "array index : " << (int)index->type_int << "\n";
  if (DEBUG)
    for (int j=0; (unsigned)j < array->array_type->array->size(); ++j) {
      int value = (array->array_type->array->at(j))->type_bool;
      cout << "array item : " << value << "\n";
    }
  curr_frame->push_operand(op);

  curr_frame->pc++;
  if (DEBUG) cout << "baload\n";
}

/**
* @brief Coleta um char do vetor de referência e coloca na pilha.
* @param *curr_frame ponteiro para o frame atual
* @return void
*/
void caload(Frame *curr_frame) {
  Operand* index = curr_frame->pop_operand();
  Operand* array = curr_frame->pop_operand();

  if (DEBUG) cout << "array size : " << array->array_type->array->size()
                        << "\n";
  Operand* op = array->array_type->array->at(index->type_int);
  if (DEBUG) cout << "array index : " << (int)index->type_int << "\n";
  if (DEBUG)
    for (int j=0; (unsigned)j < array->array_type->array->size(); ++j) {
      int value = (array->array_type->array->at(j))->type_char;
      cout << "array item : " << value << "\n";
    }
  curr_frame->push_operand(op);

  curr_frame->pc++;
  if (DEBUG) cout << "caload\n";
}

/**
* @brief Coleta um char do vetor de referência e coloca na pilha.
* @param *curr_frame ponteiro para o frame atual
* @return void
*/
void saload(Frame *curr_frame) {
  Operand* index = curr_frame->pop_operand();
  Operand* array = curr_frame->pop_operand();

  if (DEBUG) cout << "array size : " << array->array_type->array->size()
                        << "\n";
  Operand* op = array->array_type->array->at(index->type_int);
  if (DEBUG) cout << "array index : " << (int)index->type_int << "\n";
  if (DEBUG)
    for (int j=0; (unsigned)j < array->array_type->array->size(); ++j) {
      int value = (array->array_type->array->at(j))->type_short;
      cout << "array item : " << value << "\n";
    }
  curr_frame->push_operand(op);

  curr_frame->pc++;
  if (DEBUG) cout << "saload\n";
}


/*************************** STORES ***************************/

/*
* @brief Armazena um inteiro no array de variaveis locais no valor indicado
*   pelo indice.
* @param *curr_frame Ponteiro para o frame atual
* @return void
*/
void istore(Frame *curr_frame) {
  if (DEBUG) cout << "\n----------istore----------\n";  
  curr_frame->pc++;

  u1 index = curr_frame->method_code->code[curr_frame->pc++];
  if (DEBUG) cout << "istore index " << (int)index << "\n";

  Operand *value = curr_frame->pop_operand();
  curr_frame->local_variables_array.at((int)index) = value;

 }

/**
 * @brief Armazena um inteiro no array de variaveis locais no indice 0
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void istore_0(Frame *curr_frame) {
  if (DEBUG) cout << "\n----------istore_0----------\n";  

  Operand *value = curr_frame->pop_operand();
  curr_frame->local_variables_array.at(0) = value;

  curr_frame->pc++;
}

/**
 * @brief Armazena um inteiro no array de variaveis locais no indice 1
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void istore_1(Frame *curr_frame) {
  if (DEBUG) cout << "\n----------istore_1----------\n";  

  Operand *value = curr_frame->pop_operand();
  curr_frame->local_variables_array.at(1) = value;

  curr_frame->pc++;
}

/**
 * @brief Armazena um inteiro no array de variaveis locais no indice 2
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void istore_2(Frame *curr_frame) {
  if (DEBUG) cout << "\n----------istore_2----------\n";  

  Operand *value = curr_frame->pop_operand();
  curr_frame->local_variables_array.at(2) = value;

  curr_frame->pc++;
}

/**
 * @brief Armazena um inteiro no array de variaveis locais no indice 0
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void istore_3(Frame *curr_frame) {
  if (DEBUG) cout << "\n----------istore_3----------\n";  

  Operand *value = curr_frame->pop_operand();
  curr_frame->local_variables_array.at(3) = value;

  curr_frame->pc++;

}

/**
* @brief ...
* @param *curr_frame ponteiro para o frame atual
* @return void
*/
void astore(Frame *curr_frame) {
  curr_frame->pc++;

  u1 index = curr_frame->method_code->code[curr_frame->pc++];

  Operand *operand = curr_frame->pop_operand();
  curr_frame->local_variables_array.at(index) = operand;
}

/** @brief Guarda referência do object ou array do operando na variável local -0.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void astore_0(Frame *curr_frame) {
  curr_frame->pc++;
  Operand *op = curr_frame->pop_operand();
  curr_frame->local_variables_array.at(0) = op;
}

/** @brief Guarda referência do object ou array do operando na variável local 1.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void astore_1(Frame *curr_frame) {
  curr_frame->pc++;
  Operand *op = curr_frame->pop_operand();
  curr_frame->local_variables_array.at(1) = op;
}

/** @brief Retira o topo da pilha e armazena na variavel local de posição 2.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void astore_2(Frame *curr_frame) {
  curr_frame->pc++;
  Operand *op = curr_frame->pop_operand();
  curr_frame->local_variables_array.at(2) = op;
  if (DEBUG) cout << "astore_2\n";
}

/** @brief Retira o topo da pilha e armazena na variavel local de posição 3.
@param Frame *curr_frame ponteiro para o frame atual
@return void
*/
void astore_3(Frame *curr_frame) {
    curr_frame->pc++;
    Operand *op = curr_frame->pop_operand();
    curr_frame->local_variables_array.at(3) = op;
}

/**
 * @brief Armazena valor double da pilha de operandos no array de variaveis
 *  locais no indice index
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dstore(Frame* curr_frame) {
  curr_frame->pc++;

  u1 index = curr_frame->method_code->code[curr_frame->pc++];
  if (DEBUG) cout << "dstore index " << (int)index << "\n";
  Operand *op = curr_frame->pop_operand();

  curr_frame->local_variables_array.at((int)index) = op;

  if (DEBUG) cout << "dstore\n";
}

/**
 * @brief Armazena valor double da pilha de operandos no array de variaveis locais no indice 0
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dstore_0(Frame* curr_frame) {
  Operand *op = curr_frame->operand_stack.top();
  curr_frame->operand_stack.pop();

  curr_frame->local_variables_array[0] = op;
  curr_frame->pc++;
}

/**
 * @brief Armazena valor double da pilha de operandos no array de variaveis locais no indice 1
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dstore_1(Frame* curr_frame) {
  Operand *op = curr_frame->pop_operand();

  curr_frame->local_variables_array[1] = op;
  curr_frame->pc++;

  if (DEBUG) cout << "dstore_1\n";
}

/**
 * @brief Armazena valor double da pilha de operandos no array de variaveis locais no indice 2
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dstore_2(Frame* curr_frame) {
  Operand *op = curr_frame->operand_stack.top();
  curr_frame->operand_stack.pop();

  curr_frame->local_variables_array[2] = op;
  curr_frame->pc++;
}

/**
 * @brief Armazena valor double da pilha de operandos no array de variaveis locais no indice 3
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dstore_3(Frame* curr_frame) {

  Operand *op = curr_frame->operand_stack.top();
  curr_frame->operand_stack.pop();

  curr_frame->local_variables_array[3] = op;
  curr_frame->pc++;
}

/**
 * @brief Armazena float do topo da pilha de operandos no array de variaveis
 *  locais
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fstore(Frame* curr_frame) {
  curr_frame->pc++;

  u1 index = curr_frame->method_code->code[curr_frame->pc++];
  if (DEBUG) cout << "fstore index " << (int)index << "\n";
  Operand *op = curr_frame->pop_operand();

  curr_frame->local_variables_array[(int)index] = op;

  if (DEBUG) cout << "fstore\n";
}

/**
 * @brief Armazena float do topo da pilha de operandos no array de variaveis locais no indice 0
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fstore_0(Frame* curr_frame) {
  Operand *op = curr_frame->operand_stack.top();
  curr_frame->operand_stack.pop();

  curr_frame->local_variables_array[0] = op;
  curr_frame->pc++;
}

/**
* @brief Armazena float do topo da pilha de operandos no array de variaveis locais no indice 1
* @param *curr_frame Ponteiro para o frame atual
* @return void
*/
void fstore_1(Frame* curr_frame) {
  Operand *op = curr_frame->operand_stack.top();
  curr_frame->operand_stack.pop();

  curr_frame->local_variables_array[1] = op;
  curr_frame->pc++;

  if (DEBUG) cout << "fstore_1\n" << "\n";
}

/**
* @brief Armazena float do topo da pilha de operandos no array de variaveis locais no indice 2
* @param *curr_frame Ponteiro para o frame atual
* @return void
*/
void fstore_2(Frame* curr_frame) {
  Operand *op = curr_frame->operand_stack.top();
  curr_frame->operand_stack.pop();

  curr_frame->local_variables_array[2] = op;
  curr_frame->pc++;
}

/**
* @brief Armazena float do topo da pilha de operandos no array de variaveis
* locais no indice 3
* @param *curr_frame Ponteiro para o frame atual
* @return void
*/
void fstore_3(Frame* curr_frame) {
   Operand *op = curr_frame->pop_operand();

   curr_frame->local_variables_array[3] = op;
   curr_frame->pc++;

   if (DEBUG) cout << "fstore_3\n";
 }

/*
* @brief Armazena long do topo da pilha de operandos no array de variaveis
*   locais no indice index
* @param *curr_frame Ponteiro para o frame atual
* @return void
*/
void lstore(Frame* curr_frame) {
  curr_frame->pc++;

  u1 index = curr_frame->method_code->code[curr_frame->pc++];
  if (DEBUG) cout << "lstore index " << (int)index << "\n";
  Operand *op = curr_frame->pop_operand();

  curr_frame->local_variables_array.at((int)index) = op;

  if (DEBUG) cout << "lstore\n";
}

/**
* @brief Armazena long do topo da pilha de operandos no array de variaveis locais no indice 0
* @param Frame *curr_frame Ponteiro para o frame atual
* @return void
*/
void lstore_0(Frame* curr_frame) {
 Operand *op = curr_frame->operand_stack.top();
 curr_frame->operand_stack.pop();

 curr_frame->local_variables_array[0] = op;
 curr_frame->pc++;
}

/**
* @brief Armazena long do topo da pilha de operandos no array de variaveis locais no indice 1
* @param Frame *curr_frame Ponteiro para o frame atual
* @return void
*/
void lstore_1(Frame* curr_frame) {
  Operand *op = curr_frame->operand_stack.top();
  curr_frame->operand_stack.pop();

  curr_frame->local_variables_array[1] = op;
  curr_frame->pc++;
  if (DEBUG) cout << "lstore_1\n";

}

/**
* @brief Armazena long do topo da pilha de operandos no array de variaveis locais no indice 2
* @param Frame *curr_frame Ponteiro para o frame atual
* @return void
*/
void lstore_2(Frame* curr_frame) {
 Operand *op = curr_frame->operand_stack.top();
 curr_frame->operand_stack.pop();

 curr_frame->local_variables_array[2] = op;
 curr_frame->pc++;
}

/**
* @brief Armazena long do topo da pilha de operandos no array de variaveis locais no indice 3
* @param Frame *curr_frame Ponteiro para o frame atual
* @return void
*/
void lstore_3(Frame* curr_frame) {
  Operand *op = curr_frame->operand_stack.top();
  curr_frame->operand_stack.pop();

  curr_frame->local_variables_array[3] = op;
  curr_frame->pc++;
  if (DEBUG) cout << "lstore_3\n";
}

/**
 * @brief Coleta um int da pilha de operandos e armazena em um vetor de ints.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void iastore(Frame* curr_frame) {
  Operand* value = curr_frame->pop_operand();
  Operand* index = curr_frame->pop_operand();
  Operand *array = curr_frame->pop_operand();

  ((*array->array_type->array)[(int)index->type_int])->type_int = value->type_int;

  if (DEBUG) cout << "iastore value : " << value->type_int << "\n";
  if (DEBUG)
    for (int j=0; (unsigned)j < array->array_type->array->size(); ++j) {
      int value = (array->array_type->array->at(j))->type_int;
      if (DEBUG) cout << "array item : " << value << "\n";
    }

  curr_frame->push_operand(array);
  curr_frame->pc++;

  if (DEBUG) cout << "iastore\n";
}

/**
 * @brief Coleta um long da pilha de operandos e armazena em um vetor de longs.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void lastore(Frame* curr_frame) {
  Operand* value = curr_frame->pop_operand();
  Operand* index = curr_frame->pop_operand();
  Operand *array = curr_frame->pop_operand();

  ((*array->array_type->array)[(int)index->type_int])->type_long = value->type_long;

  if (DEBUG) cout << "lastore value : " << value->type_long << "\n";
  if (DEBUG)
    for (int j=0; (unsigned)j < array->array_type->array->size(); ++j) {
      int value = (array->array_type->array->at(j))->type_long;
      if (DEBUG) cout << "array item : " << value << "\n";
    }

  curr_frame->push_operand(array);
  curr_frame->pc++;

  if (DEBUG) cout << "lastore\n";
}

/**
 * @brief Coleta um float da pilha de operandos e armazena em um vetor de floats.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void fastore(Frame* curr_frame) {
  Operand* value = curr_frame->pop_operand();
  Operand* index = curr_frame->pop_operand();
  Operand *array = curr_frame->pop_operand();

  ((*array->array_type->array)[(int)index->type_int])->type_float = value->type_float;

  if (DEBUG) cout << "fastore value : " << value->type_float << "\n";
  if (DEBUG)
    for (int j=0; (unsigned)j < array->array_type->array->size(); ++j) {
      int value = (array->array_type->array->at(j))->type_float;
      if (DEBUG) cout << "array item : " << value << "\n";
    }

  curr_frame->push_operand(array);
  curr_frame->pc++;

  if (DEBUG) cout << "fastore\n";
}

/**
 * @brief Coleta um double da pilha de operandos e armazena em um vetor de doubles.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void dastore(Frame* curr_frame) {
  Operand* value = curr_frame->pop_operand();
  Operand* index = curr_frame->pop_operand();
  Operand *array = curr_frame->pop_operand();

  ((*array->array_type->array)[(int)index->type_int])->type_double = value->type_double;

  if (DEBUG) cout << "dastore value : " << value->type_double << "\n";
  if (DEBUG)
    for (int j=0; (unsigned)j < array->array_type->array->size(); ++j) {
      int value = (array->array_type->array->at(j))->type_double;
      if (DEBUG) cout << "array item : " << value << "\n";
    }

  curr_frame->push_operand(array);
  curr_frame->pc++;

  if (DEBUG) cout << "dastore\n";
}

/**
 * @brief Coleta um objeto da pilha de operandos e armazena em um vetor de objetos.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void aastore(Frame* curr_frame) {
  Operand* value = curr_frame->pop_operand();
  Operand* index = curr_frame->pop_operand();
  Operand *array = curr_frame->pop_operand();

  ((*array->array_type->array)[(int)index->type_int])->array_type = value->array_type;

  if (DEBUG) cout << "aastore value : " << value->array_type << "\n";
  if (DEBUG)
    for (int j=0; (unsigned)j < array->array_type->array->size(); ++j) {
      int value = (array->array_type->array->at(j))->array_type->array->size();
      if (DEBUG) cout << "sub array size : " << value << "\n";
    }

  curr_frame->push_operand(array);
  curr_frame->pc++;

  if (DEBUG) cout << "aastore\n";
}

/**
 * @brief Coleta um booleano da pilha de operandos e armazena em um vetor de booleanos.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void bastore(Frame* curr_frame) {
  Operand* value = curr_frame->pop_operand();
  Operand* index = curr_frame->pop_operand();
  Operand *array = curr_frame->pop_operand();

  ((*array->array_type->array)[(int)index->type_int])->type_bool = value->type_bool;

  if (DEBUG) cout << "bastore value : " << value->type_bool << "\n";
  if (DEBUG)
    for (int j=0; (unsigned)j < array->array_type->array->size(); ++j) {
      int value = (array->array_type->array->at(j))->type_bool;
      if (DEBUG) cout << "array item : " << value << "\n";
    }

  curr_frame->push_operand(array);
  curr_frame->pc++;

  if (DEBUG) cout << "bastore\n";
}

/**
 * @brief Coleta um 32-bit integer da pilha de operandos e armazena em um vetor
 *  16-bit unsigned (char).
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void castore(Frame* curr_frame) {
  Operand* value = curr_frame->pop_operand();
  Operand* index = curr_frame->pop_operand();
  Operand *array = curr_frame->pop_operand();

  ((*array->array_type->array)[(int)index->type_int])->type_char = value->type_char;

  if (DEBUG) cout << "castore value : " << value->type_char << "\n";
  if (DEBUG)
    for (int j=0; (unsigned)j < array->array_type->array->size(); ++j) {
      int value = (array->array_type->array->at(j))->type_char;
      if (DEBUG) cout << "array item : " << value << "\n";
    }

  curr_frame->push_operand(array);
  curr_frame->pc++;

  if (DEBUG) cout << "castore\n";
}

/**
 * @brief Coleta um short da pilha de operandos e armazena em um vetor shorts
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void sastore(Frame* curr_frame) {
  Operand* value = curr_frame->pop_operand();
  Operand* index = curr_frame->pop_operand();
  Operand *array = curr_frame->pop_operand();

  ((*array->array_type->array)[(int)index->type_int])->type_short = value->type_short;

  if (DEBUG) cout << "sastore value : " << value->type_short << "\n";
  if (DEBUG)
    for (int j=0; (unsigned)j < array->array_type->array->size(); ++j) {
      int value = (array->array_type->array->at(j))->type_short;
      if (DEBUG) cout << "array item : " << value << "\n";
    }

  curr_frame->push_operand(array);
  curr_frame->pc++;

  if (DEBUG) cout << "sastore\n";
}


/*************************** STACK ***************************/

void pop(Frame *curr_frame) {
  curr_frame->pc++;
  curr_frame->pop_operand();
}

void pop2(Frame *curr_frame) {
  curr_frame->pc++;
  Operand *operand = curr_frame->pop_operand();

  if (operand->tag != CONSTANT_LONG && operand->tag != CONSTANT_DOUBLE)
    curr_frame->pop_operand();
}

/**
 * @brief Faz uma cópia do item que está no topo da pilha e o adiciona ao
 *  topo da pilha.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void dup(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *copy_1 = copy_operand(curr_frame->operand_stack.top());

  if (DEBUG) cout << "top array size "
                      << copy_1->array_type->array->size()
                      << "\n";

  curr_frame->push_operand(copy_1);

  if (DEBUG) cout << "dup\n";
}

/**
 * @brief Duplica o item no topo da pilha e pusha depois do segundo elemento da pilha.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void dup_x1(Frame *curr_frame) {
    curr_frame->pc++;
    Operand *value = curr_frame->pop_operand();
    Operand *value2 = curr_frame->pop_operand();
    if (
      value->tag == CONSTANT_DOUBLE || value->tag == CONSTANT_LONG || 
      value2->tag == CONSTANT_DOUBLE || value2->tag == CONSTANT_LONG
    ) {
        curr_frame->push_operand(value2);
        curr_frame->push_operand(value);
    } else {
        Operand *tipo = copy_operand(value);
        curr_frame->push_operand(tipo);
        curr_frame->push_operand(value2);
        curr_frame->push_operand(value);
    }
}

/**
 * @brief Duplica o item no topo da pilha e pusha depois do terceiro elemento da pilha
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void dup_x2(Frame *curr_frame) {
    curr_frame->pc++;
    Operand* value = curr_frame->pop_operand();
    Operand* value2 = curr_frame->pop_operand();

    if (value->tag != CONSTANT_DOUBLE && value->tag != CONSTANT_LONG) {
        if (value2->tag == CONSTANT_DOUBLE || value2->tag == CONSTANT_LONG) {
            Operand* tipo = copy_operand(value);
            curr_frame->push_operand(tipo);
            curr_frame->push_operand(value2);
            curr_frame->push_operand(value);

        }
        else {
            Operand* value3 = curr_frame->pop_operand();
            if (value3->tag != CONSTANT_DOUBLE && value3->tag != CONSTANT_LONG) {
                Operand* tipo = copy_operand(value);
                curr_frame->push_operand(tipo);
                curr_frame->push_operand(value3);
                curr_frame->push_operand(value2);
                curr_frame->push_operand(value);
            }
        }
    }
}

/**
 * @brief Faz uma cópia de dois itens que estao no topo da pilha e o(s) adiciona ao topo da pilha.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void dup2(Frame *curr_frame) {
    curr_frame->pc++;
    Operand *value1 = curr_frame->pop_operand();
    if (value1->tag != CONSTANT_DOUBLE && value1->tag != CONSTANT_LONG) {
        Operand *value2 = curr_frame->pop_operand();

        Operand *tipo1 = copy_operand(value1);
        Operand *tipo2 = copy_operand(value2);

        curr_frame->push_operand(tipo2);
        curr_frame->push_operand(tipo1);

        curr_frame->push_operand(value2);
        curr_frame->push_operand(value1);

    } else {
        Operand *tipo = copy_operand(value1);
        curr_frame->push_operand(tipo);
        curr_frame->push_operand(value1);
    }
}

/**
 * @brief Duplica um ou dois valores da pilha de operandos e insere os valores duplicados na ordem original
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void dup2_x1(Frame *curr_frame) {
    curr_frame->pc++;
    Operand *value1 = curr_frame->pop_operand();
    Operand *value2 = curr_frame->pop_operand();

    if (value1->tag != CONSTANT_DOUBLE && value1->tag != CONSTANT_LONG) {
        Operand* value3 = curr_frame->pop_operand();

        Operand *tipo1 = copy_operand(value1);
        Operand *tipo2 = copy_operand(value2);

        curr_frame->push_operand(tipo2);
        curr_frame->push_operand(tipo1);

        curr_frame->push_operand(value3);

        curr_frame->push_operand(value2);
        curr_frame->push_operand(value1);
    } else {
        Operand* tipo1 = copy_operand(value1);

        curr_frame->push_operand(tipo1);
        curr_frame->push_operand(value2);
        curr_frame->push_operand(value1);
    }
}

/**
 * @brief Duplica um ou dois operandos da pilha e insere os valores duplicados na ordem original
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void dup2_x2(Frame *curr_frame) {
    curr_frame->pc++;
    Operand* value1 = curr_frame->pop_operand();
    Operand* value2 = curr_frame->pop_operand();

    Operand* tipo1 = copy_operand(value1);
    if (value1->tag != CONSTANT_DOUBLE && value1->tag != CONSTANT_LONG && value2->tag != CONSTANT_DOUBLE && value2->tag != CONSTANT_LONG) {
        Operand* value3 = curr_frame->pop_operand();
        Operand* tipo2 = copy_operand(value2);

        if (value3->tag != CONSTANT_DOUBLE && value3->tag != CONSTANT_LONG) {
            Operand* value4 = curr_frame->pop_operand();

            curr_frame->push_operand(tipo2);
            curr_frame->push_operand(tipo1);

            curr_frame->push_operand(value4);
            curr_frame->push_operand(value3);

            curr_frame->push_operand(value2);
            curr_frame->push_operand(value1);
        } else {
            curr_frame->push_operand(tipo2);
            curr_frame->push_operand(tipo1);

            curr_frame->push_operand(value3);
            curr_frame->push_operand(value2);
            curr_frame->push_operand(value1);
        }
    }
    else {
        if (value2->tag == CONSTANT_DOUBLE || value2->tag == CONSTANT_LONG) {
            curr_frame->push_operand(tipo1);
            curr_frame->push_operand(value2);
            curr_frame->push_operand(value1);
        }
        else {
            Operand* value3 = curr_frame->pop_operand();

            curr_frame->push_operand(tipo1);
            curr_frame->push_operand(value3);
            curr_frame->push_operand(value2);
            curr_frame->push_operand(value1);
        }
    }
}

void swap(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  curr_frame->push_operand(operand_1);
  curr_frame->push_operand(operand_2);
}


/*************************** MATH ***************************/

/**
 * @brief Soma de inteiros. Retira os dois operando do topo da pilha, soma-os e coloca o resultado
 * no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void iadd(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  Operand *result = (Operand *) malloc(sizeof(Operand));

  result->tag = CONSTANT_INT;
  result->type_int = operand_1->type_int + operand_2->type_int;

  curr_frame->push_operand(result);

  if (DEBUG) cout << "iadd\n";
}

/**
 * @brief Soma do tipo long. Retira os dois operando do topo da pilha, soma-os e coloca o resultado
 * no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void ladd(Frame *curr_frame) {
  curr_frame->pc++;
  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_LONG;
  result->type_long = operand_1->type_long + operand_2->type_long;

  curr_frame->push_operand(result);
  if (DEBUG) cout << "ladd\n";

}

/**
 * @brief Soma do tipo float. Retira os dois operando do topo da pilha, soma-os e coloca o resultado
 * no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fadd(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  float value_1, value_2;
  memcpy(&value_1, &operand_1->type_float, sizeof(float));
  memcpy(&value_2, &operand_2->type_float, sizeof(float));
  value_1 += value_2;

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_FLOAT;
  memcpy(&result->type_float, &value_1, sizeof(u4));

  curr_frame->push_operand(result);

  if (DEBUG) cout << "fadd\n";
}

/**
 * @brief Soma do tipo double. Retira os dois operando do topo da pilha, soma-os e coloca o resultado
 * no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
 void dadd(Frame *curr_frame) {
   curr_frame->pc++;

   Operand *operand_1 = curr_frame->pop_operand();
   Operand *operand_2 = curr_frame->pop_operand();

   double value_1, value_2;
   memcpy(&value_1, &operand_1->type_double, sizeof(double));
   memcpy(&value_2, &operand_2->type_double, sizeof(double));
   value_1 += value_2;
   if (DEBUG) cout << "dadd value " << value_1 << "\n";

   Operand *result = (Operand *) malloc(sizeof(Operand));
   result->tag = CONSTANT_DOUBLE;
   memcpy(&result->type_double, &value_1, sizeof(u8));

   curr_frame->push_operand(result);

   if (DEBUG) cout << "dadd\n";
 }

/**
 * @brief Subtração do tipo inteiro. Retira os dois operando do topo da pilha,
 *  subtraí-os e coloca o resultado no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void isub(Frame *curr_frame) {
  curr_frame->pc++;
  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_INT;
  result->type_int = operand_2->type_int - operand_1->type_int;

  curr_frame->push_operand(result);

  if (DEBUG) cout << "isub\n";
}

/**
 * @brief Subtração do tipo long. Retira os dois operando do topo da pilha, subtraí-os e coloca o
 * resultado no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lsub(Frame *curr_frame) {
  curr_frame->pc++;
  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_LONG;
  result->type_long = operand_2->type_long - operand_1->type_long;

  curr_frame->push_operand(result);
  if (DEBUG) cout << "lsub\n";

}

/**
 * @brief Subtração do tipo float. Retira os dois operando do topo da pilha, subtraí-os e coloca o
 * resultado no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fsub(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  float value_1, value_2;
  memcpy(&value_1, &operand_1->type_float, sizeof(float));
  memcpy(&value_2, &operand_2->type_float, sizeof(float));
  value_2 -= value_1;

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_FLOAT;
  memcpy(&result->type_float, &value_2, sizeof(u4));

  curr_frame->push_operand(result);

  if (DEBUG) cout << "fsub\n";
}

/**
 * @brief Subtração do tipo double. Retira os dois operando do topo da pilha,
 *  subtraí-os e coloca o resultado no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dsub(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  double value_1, value_2;
  memcpy(&value_1, &operand_1->type_float, sizeof(double));
  memcpy(&value_2, &operand_2->type_float, sizeof(double));
  value_2 -= value_1;

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_DOUBLE;
  memcpy(&result->type_double, &value_2, sizeof(u8));

  curr_frame->push_operand(result);

  if (DEBUG) cout << "dsub\n";
}

/**
 * @brief Multiplicação de inteiros. Retira os dois operando do topo da pilha,
 *  multiplica-os e coloca o resultado no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void imul(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_INT;
  result->type_int = (operand_1->type_int) * (operand_2->type_int);

  curr_frame->push_operand(result);

  if (DEBUG) cout << "imul\n";
}

/**
 * @brief Multiplicação de long. Retira os dois operando do topo da pilha, multiplica-os
 * e coloca o resultado no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lmul(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_LONG;
  result->type_long = (operand_1->type_long) * (operand_2->type_long);

  curr_frame->push_operand(result);
  if (DEBUG) cout << "lmul\n";

}

/**
 * @brief Multiplicação de float. Retira os dois operando do topo da pilha, multiplica-os
 * e coloca o resultado no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fmul(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  float value_1, value_2;
  memcpy(&value_1, &operand_1->type_float, sizeof(float));
  memcpy(&value_2, &operand_2->type_float, sizeof(float));
  value_2 *= value_1;

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_FLOAT;
  memcpy(&result->type_float, &value_2, sizeof(u4));

  curr_frame->push_operand(result);

  if (DEBUG) cout << "fmul\n";
}

/**
 * @brief Multiplicação de double. Retira os dois operando do topo da pilha,
 *  multiplica-os e coloca o resultado no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dmul(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  double value_1, value_2;
  memcpy(&value_1, &operand_1->type_double, sizeof(double));
  memcpy(&value_2, &operand_2->type_double, sizeof(double));
  value_2 *= value_1;

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_DOUBLE;
  memcpy(&result->type_double, &value_2, sizeof(u8));

  curr_frame->push_operand(result);

  if (DEBUG) cout << "dmul\n";
}

/**
 * @brief Divisão de inteiro. Retira os dois operandos do topo da pilha,
 *  divide-os e coloca o resultado no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void idiv(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_INT;
  result->type_int = (operand_2->type_int) / (operand_1->type_int);

  curr_frame->push_operand(result);

  if (DEBUG) cout << "idiv\n";
}

/**
 * @brief Divisão de long. Retira os dois operandos do topo da pilha, divide-os
 * e coloca o resultado no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void ldiv(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_LONG;
  result->type_long = (operand_2->type_long) / (operand_1->type_long);

  curr_frame->push_operand(result);
  if (DEBUG) cout << "ldiv\n";
}

/**
 * @brief Divisão de float. Retira os dois operandos do topo da pilha, divide-os
 * e coloca o resultado no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fdiv(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  float value_1, value_2;
  memcpy(&value_1, &operand_1->type_float, sizeof(float));
  memcpy(&value_2, &operand_2->type_float, sizeof(float));
  value_2 /= value_1;

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_FLOAT;
  memcpy(&result->type_float, &value_2, sizeof(u4));

  curr_frame->push_operand(result);
}

/**
 * @brief Divisão de double. Retira os dois operandos do topo da pilha,
 *  divide-os e coloca o resultado no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void ddiv(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  double value_1, value_2;
  memcpy(&value_1, &operand_1->type_double, sizeof(double));
  memcpy(&value_2, &operand_2->type_double, sizeof(double));
  value_2 /= value_1;

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_DOUBLE;
  memcpy(&result->type_double, &value_2, sizeof(u8));
  if (DEBUG) cout << "ddiv result : " << result->type_double << "\n";

  curr_frame->push_operand(result);

  if (DEBUG) cout << "ddiv\n";
}

/**
 * @brief Calcula o resto da divisão entre dois inteiros.
 *  Retira os dois operandos do topo da pilha, calcula o resto da divisão e
 *  coloca no topo.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void irem(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  u4 divider = operand_1->type_int;
  u4 dividend = operand_2->type_int;

  u4 i_remainder = (u4) dividend - (dividend / divider) * divider;

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_INT;
  result->type_int = i_remainder;

  curr_frame->push_operand(result);

  if (DEBUG) cout << "irem\n";
}

/**
 * @brief Calcula o resto da divisão entre dois long. Retira os dois operandos do topo da pilha,
 * calcula o resto da divisão e coloca no topo.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lrem(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  u8 divider = operand_1->type_int;
  u8 dividend = operand_2->type_int;

  u8 l_remainder = dividend - (dividend / divider) * divider;

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_LONG;
  result->type_int = l_remainder;

  curr_frame->push_operand(result);
}

/**
 * @brief Calcula o resto da divisão entre dois floats
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void frem(Frame *curr_frame) {
    float dividend, divisor, f_remainder;

    curr_frame->pc++;
    Operand *op1 = curr_frame->pop_operand();
    Operand *op2 = curr_frame->pop_operand();

    memcpy(&divisor, &op1->type_float, sizeof(float));
    memcpy(&dividend, &op2->type_float, sizeof(float));

    f_remainder = std::fmod(dividend, divisor);

    Operand *result = (Operand*)malloc(sizeof(Operand));
    result->tag = CONSTANT_FLOAT;
    memcpy(&result->type_float, &f_remainder, sizeof(u4));
    curr_frame->push_operand(result);
}

/**
 * @brief Calcula o resto da divisão entre dois double. Retira os dois
 *  operandos do topo da pilha, calcula o resto da divisão e coloca no topo.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void drem(Frame *curr_frame) {
  double dividend, divisor, f_remainder;

  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  memcpy(&divisor, &operand_1->type_double, sizeof(double));
  memcpy(&dividend, &operand_2->type_double, sizeof(double));
  f_remainder = std::fmod(dividend, divisor);

  Operand *result = check_string_create_type("D");
  memcpy(&result->type_double, &f_remainder, sizeof(u8));
  curr_frame->push_operand(result);
}

/**
 * @brief Calcula o valor negativo de int. Retira o operando do topo da pilha, nega o valor do
 * operando e o salva o resultado no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void ineg(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand = curr_frame->pop_operand();
  Operand *result = check_string_create_type("I");
  result->type_int = -(u4)operand->type_int;

  curr_frame->push_operand(result);
}

/**
 * @brief Calcula o valor negativo de long. Retira o operando do topo da pilha, nega o valor do
 * operando e o salva o resultado no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lneg(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand = curr_frame->pop_operand();
  u8 l_value = operand->type_long;
  u8 l_result = -l_value;

  Operand *result = check_string_create_type("J");
  result->type_long = l_result;

  curr_frame->push_operand(result);
}

/**
 * @brief Calcula o valor negativo de float. Retira o operando do topo da pilha, nega o valor do
 * operando e o salva o resultado no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fneg(Frame *curr_frame) {
  float f_value;

  curr_frame->pc++;

  Operand *operand = curr_frame->pop_operand();
  memcpy(&f_value, &operand->type_float, sizeof(float));
  f_value = -f_value;

  Operand *result = check_string_create_type("F");
  memcpy(&result->type_float, &f_value, sizeof(u4));

  curr_frame->push_operand(result);
}

/**
 * @brief Calcula o valor negativo de double. Retira o operando do topo da pilha, nega o valor do
 * operando e o salva o resultado no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dneg(Frame *curr_frame) {
  double d_value;
  curr_frame->pc++;

  Operand *operand = curr_frame->pop_operand();
  memcpy(&d_value, &operand->type_double, sizeof(double));
  d_value = -d_value;

  Operand *result = check_string_create_type("D");
  memcpy(&result->type_double, &d_value, sizeof(u8));

  curr_frame->push_operand(result);
}

/**
 * @brief Calcula o valor do shift left lógico para inteiro. Retira dois operandos do topo da pilha
 * e faz o shift left do primeiro operando por s posições, onde s são os 5 bits menos significativos
 * do segundo operando. O resultado é colocado no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void ishl(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  u4 i_value_1 = operand_1->type_int;
  u4 i_value_2 = operand_2->type_int;

  i_value_2 &= 0x0000001f;

  u4 i_result = i_value_1 << i_value_2;
  Operand *result = check_string_create_type("I");

  result->type_int = i_result;

  curr_frame->push_operand(result);
}

/**
 * @brief Calcula o valor do shift left lógico para long. Retira dois operandos do topo da pilha
 * e faz o shift left do primeiro operando por s posições, onde s são os 5 bits menos significativos
 * do segundo operando. O resultado é colocado no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lshl(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  u8 l_value_1 = operand_1->type_long;
  u8 l_value_2 = operand_2->type_long;

  l_value_2 &= 0x0000003f;

  u8 l_result = l_value_1 << l_value_2;

  Operand *result = check_string_create_type("J");

  result->type_long = l_result;

  curr_frame->push_operand(result);
}

/**
 * @brief Calcula o valor do shift right lógico para inteiro. Retira dois operandos do topo da pilha
 * e faz o shift right do primeiro operando por s posições, onde s são os 5 bits menos significativos
 * do segundo operando. O resultado é colocado no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void ishr(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  u4 l_value_1 = operand_1->type_int;
  u4 l_value_2 = operand_2->type_int;

  u4 l_result = (u4) (l_value_1 / pow(2, l_value_2));

  Operand *result = check_string_create_type("I");
  result->type_int = l_result;

  curr_frame->push_operand(result);
}

/**
 * @brief Calcula o valor do shift right lógico para long. Retira dois operandos do topo da pilha
 * e faz o shift right do primeiro operando por s posições, onde s são os 5 bits menos significativos
 * do segundo operando. O resultado é colocado no topo da pilha.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lshr(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  u8 l_value_1 = operand_1->type_long;
  u8 l_value_2 = operand_2->type_long;
  u8 l_result = (u8) (l_value_1 / pow(2, l_value_2 & 0x3f));

  Operand *result = check_string_create_type("J");
  result->type_long = (u8) l_result;

  curr_frame->push_operand(result);
}

void iushr(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  u4 i_value_1 = operand_1->type_int;
  u4 i_value_2 = operand_2->type_int;

  i_value_2 &= 0x0000001f;

  u4 i_result = i_value_1 >> i_value_2;
  Operand *result = check_string_create_type("I");

  result->type_int = i_result;

  curr_frame->push_operand(result);
}

void lushr(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  u4 i_value_1 = operand_1->type_long;
  u4 i_value_2 = operand_2->type_long;

  i_value_2 &= 0x0000003f;

  u4 i_result = i_value_1 >> i_value_2;
  Operand *result = check_string_create_type("J");

  result->type_long = i_result;

  curr_frame->push_operand(result);
}

void iand(Frame *curr_frame) {
    u4 ivalue1, ivalue2, iresult;
    curr_frame->pc++;

    Operand *value1 = curr_frame->pop_operand();
    Operand *value2 = curr_frame->pop_operand();

    ivalue1 = value1->type_int;
    ivalue2 = value2->type_int;
    iresult = ivalue1 & ivalue2;

    Operand *result = check_string_create_type("I");
    result->type_int = (u4)iresult;

    curr_frame->push_operand(result);
}

void land(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  u8 i_value_1 = operand_1->type_long;
  u8 i_value_2 = operand_2->type_long;
  u8 i_result = i_value_1 & i_value_2;

  Operand *result = check_string_create_type("J");

  result->type_long = (u8) i_result;

  curr_frame->push_operand(result);
}

/**
 * @brief Realiza a operacao de OR entre dois operandos e empilha o resultado
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void ior(Frame *curr_frame) {
    u4 ivalue1, ivalue2, iresult;

    curr_frame->pc++;

    Operand *value1 = curr_frame->pop_operand();
    Operand *value2 = curr_frame->pop_operand();

    ivalue1 = value1->type_int;
    ivalue2 = value2->type_int;

    iresult = ivalue1 | ivalue2;

    Operand* result = check_string_create_type("I");

    result->type_int = (u4)iresult;

    curr_frame->push_operand(result);
}

void lor(Frame *curr_frame) {
  curr_frame->pc++;
  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();
  u8 i_value_1 = operand_1->type_long;
  u8 i_value_2 = operand_2->type_long;
  u8 i_result = i_value_1 | i_value_2;

  Operand *result = check_string_create_type("J");
  result->type_long = (u8) i_result;
  curr_frame->push_operand(result);
}

void ixor(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  u4 i_value_1 = operand_1->type_int;
  u4 i_value_2 = operand_2->type_int;
  u4 i_result = i_value_1 ^ i_value_2;

  Operand *result = check_string_create_type("I");

  result->type_int = (u4) i_result;

  curr_frame->push_operand(result);
}

void lxor(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  u8 i_value_1 = operand_1->type_long;
  u8 i_value_2 = operand_2->type_long;
  u8 i_result = i_value_1 ^ i_value_2;

  Operand *result = check_string_create_type("I");

  result->type_long = (u8) i_result;

  curr_frame->push_operand(result);
}

/*************************** CONVERSIONS ***************************/

/**
 * @brief Incrementa uma variavel local em uma constante
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void iinc(Frame *curr_frame) {
    u1 index = curr_frame->method_code->code[curr_frame->pc++];
    u1 constant_value = curr_frame->method_code->code[curr_frame->pc++];
    curr_frame->local_variables_array.at(index) += constant_value;
    curr_frame->pc++;
}

/**
 * @brief Resgata o valor do topo da pilha (que deve ser int), covnerte para
 *  long e salva na pilha de operandos
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void i2l(Frame *curr_frame) {
    int value_op;
    Operand *op_int = curr_frame->pop_operand();
    memcpy(&value_op, &op_int->type_int, sizeof(u4));

    long value_long = (long)value_op;
    Operand *value_converted = check_string_create_type("J");
    memcpy(&value_converted->type_long, &value_long, sizeof(u8));

    curr_frame->pc++;
    curr_frame->push_operand(value_converted);
    if (DEBUG) cout << "i2l\n";
}

/**
* @brief Converte de inteiro para float
* @param *curr_frame ponteiro para o frame atual
* @return void
*/
void i2f(Frame *curr_frame) {
  int stack_value;
  Operand *operand = curr_frame->pop_operand();
  memcpy(&stack_value, &operand->type_int, sizeof(u4));

  float converted_value = (float) stack_value;
  Operand *float_converted_type = check_string_create_type("F");
  memcpy(&float_converted_type->type_float, &converted_value, sizeof(u4));

  curr_frame->pc++;
  curr_frame->push_operand(float_converted_type);
}

/**
 * @brief Converte de int para double
 * @param *curr_frame ponteiro que aponta para o frame atual
 * @return void
 */
void i2d(Frame *curr_frame) {
  int stack_value;
  Operand *int_type = curr_frame->pop_operand();
  stack_value = int_type->type_int;
  if (DEBUG) cout << "i2d int value " << stack_value << "\n";

  double d_value_cast = (double)stack_value;
  if (DEBUG) cout << "i2d double value " << d_value_cast << "\n";
  Operand *d_value_cast_type = check_string_create_type("D");
  memcpy(&d_value_cast_type->type_double, &d_value_cast, sizeof(u8));

  curr_frame->pc++;
  curr_frame->push_operand(d_value_cast_type);

  if (DEBUG) cout << "i2d\n";
}

/**
 * @brief Converte um long para int
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void l2i(Frame *curr_frame) {
    long stack_value;
    Operand *long_type = curr_frame->pop_operand();
    memcpy(&stack_value, &long_type->type_long, sizeof(u8));

    int new_value = (int) stack_value;
    Operand *new_int = check_string_create_type("I");
    memcpy(&new_int->type_int, &new_value, sizeof(u4));

    curr_frame->push_operand(new_int);
    curr_frame->pc++;
}

/**
* @brief Converte de long para float
* @param *curr_frame ponteiro para o frame atual
* @return void
*/
void l2f(Frame *curr_frame) {
  long stack_value;
  Operand *operand = curr_frame->pop_operand();
  memcpy(&stack_value, &operand->type_long, sizeof(u8));

  float converted_value = (float) stack_value;
  Operand *float_converted_type = check_string_create_type("F");
  memcpy(&float_converted_type->type_float, &converted_value, sizeof(u4));

  curr_frame->pc++;
  curr_frame->push_operand(float_converted_type);
}

/**
 * @brief Converte um long para double
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void l2d(Frame *curr_frame) {
    long stack_value;
    Operand *long_type = curr_frame->pop_operand();
    memcpy(&stack_value, &long_type->type_long, sizeof(u8));

    double new_value = (double) stack_value;
    Operand *new_double = check_string_create_type("D");
    memcpy(&new_double->type_double, &new_value, sizeof(u8));

    curr_frame->push_operand(new_double);
    curr_frame->pc++;

    if (DEBUG) cout << "l2d\n";
}

/**
 * @brief Converte de float para inteiro
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void f2i(Frame *curr_frame) {
  float float_value;
  Operand *float_type = curr_frame->pop_operand();
  float_value = float_type->type_float;
  if (DEBUG) cout << "f2i float " << float_value << "\n";

  int int_value = (int)float_value;
  Operand *new_int = check_string_create_type("I");
  memcpy(&new_int->type_int, &int_value, sizeof(u4));
  if (DEBUG) cout << "f2i int " << int_value << "\n";

  curr_frame->push_operand(new_int);
  curr_frame->pc++;

  if (DEBUG) cout << "f2i\n";
}

void f2l(Frame *curr_frame) {
  float stack_value;
  Operand *floatType = curr_frame->pop_operand();
  stack_value = floatType->type_float;
  if (DEBUG) cout << "f2l float value " << stack_value << "\n";

  long conv_value = (long)stack_value;
  Operand *longConvertidoType = check_string_create_type("J");
  memcpy(&longConvertidoType->type_long, &conv_value, sizeof(uint64_t));
  if (DEBUG) cout << "f2l long value " << longConvertidoType->type_long << "\n";

  curr_frame->pc++;
  curr_frame->push_operand(longConvertidoType);

  if (DEBUG) cout << "f2l\n";
}

/**
 * @brief Converte de float para double
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void f2d(Frame *curr_frame) {
  float float_value;
  Operand *float_type = curr_frame->pop_operand();
  float_value = float_type->type_float;
  if (DEBUG) cout << "f2d float value " << float_value << "\n";

  double double_value = (double)float_value;
  if (DEBUG) cout << "f2d double value " << double_value << "\n";
  Operand *new_double = check_string_create_type("D");
  memcpy(&new_double->type_double, &double_value, sizeof(u8));

  curr_frame->push_operand(new_double);
  curr_frame->pc++;

  if (DEBUG) cout << "f2d\n";
}

/**
 * @brief Converte de double para int
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void d2i(Frame *curr_frame) {
  double stack_value;
  Operand *double_type = curr_frame->pop_operand();
  memcpy(&stack_value, &double_type->type_double, sizeof(int64_t));

  if (DEBUG) cout << "d2i double value : " << stack_value << "\n";

  int int_value = (int)stack_value;
  Operand *new_int = check_string_create_type("I");
  memcpy(&new_int->type_int, &int_value, sizeof(u4));

  if (DEBUG) cout << "d2i int value : " << new_int->type_int << "\n";

  curr_frame->push_operand(new_int);
  curr_frame->pc++;

  if (DEBUG) cout << "d2i\n";
}

/**
 * @brief Converte de double para long
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void d2l(Frame *curr_frame) {
  double stack_value;
  Operand *double_type = curr_frame->pop_operand();
  memcpy(&stack_value, &double_type->type_double, sizeof(int64_t));

  long long_value = (long)stack_value;
  Operand *new_long = check_string_create_type("J");
  memcpy(&new_long->type_long, &long_value, sizeof(u8));

  curr_frame->push_operand(new_long);
  curr_frame->pc++;
}

/**
 * @brief Converte double para float
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void d2f(Frame *curr_frame) {
  u8 stack_value;
  Operand *double_type = curr_frame->pop_operand();
  memcpy(&stack_value, &double_type->type_double, sizeof(u8));
  if (DEBUG) cout << "d2f double value : " << stack_value << "\n";

  float float_value = (float)stack_value;
  Operand *new_float = check_string_create_type("F");
  memcpy(&new_float->type_float, &float_value, sizeof(u4));
  if (DEBUG) cout << "d2f float value : " << new_float->type_float << "\n";

  curr_frame->push_operand(new_float);
  curr_frame->pc++;

  if (DEBUG) cout << "d2f\n";
}

/**
 * @brief Converte int para short int.
 * @param *curr_frame ponteiro que aponta para o frame atual
 * @return void
 */
void i2s(Frame *curr_frame) {
  curr_frame->pc++;

  int stack_value;
  Operand *int_type = curr_frame->pop_operand();
  memcpy(&stack_value, &int_type->type_int, sizeof(uint32_t));

  short conv_value = (short)stack_value;
  Operand *op_from_type = check_string_create_type("S");
  memcpy(&op_from_type->type_byte, &conv_value, sizeof(uint32_t));

  curr_frame->push_operand(op_from_type);

  if (DEBUG) cout << "i2s\n";
}

/*************************** COMPARISONS ***************************/

void ifeq(Frame *curr_frame) {
    Operand *op = curr_frame->pop_operand();
    int val = (int)op->type_int;
    if (val == 0) {
        int shift;
        shift = curr_frame->method_code->code[curr_frame->pc + 1];
        shift = (shift << 8 ) | curr_frame->method_code->code[curr_frame->pc + 2];
        curr_frame->pc += shift;
    } else {
        curr_frame->pc +=3;
    }
}

void ifne(Frame *curr_frame) {
    Operand *op = curr_frame->pop_operand();
    int val = (int)op->type_int;
    if (val != 0) {
        int shift;
        shift = curr_frame->method_code->code[curr_frame->pc + 1];
        shift = (shift << 8 ) | curr_frame->method_code->code[curr_frame->pc + 2];
        curr_frame->pc += shift;
    } else {
        curr_frame->pc +=3;
    }
}

void iflt(Frame *curr_frame) {
    Operand *op = curr_frame->pop_operand();
    int val = (int)op->type_int;
    if (val < 0) {
        int shift;
        shift = curr_frame->method_code->code[curr_frame->pc + 1];
        shift = (shift << 8 ) | curr_frame->method_code->code[curr_frame->pc + 2];
        curr_frame->pc += shift;
    } else {
        curr_frame->pc +=3;
    }
}

void ifge(Frame *curr_frame) {
    Operand *op = curr_frame->pop_operand();
    int val = (int)op->type_int;
    if (val >= 0) {
        int shift;
        shift = curr_frame->method_code->code[curr_frame->pc + 1];
        shift = (shift << 8 ) | curr_frame->method_code->code[curr_frame->pc + 2];
        curr_frame->pc += shift;
    } else {
        curr_frame->pc +=3;
    }
}

void ifgt(Frame *curr_frame) {
    Operand *op = curr_frame->pop_operand();
    int val = (int)op->type_int;
    if (val > 0) {
        int shift;
        shift = curr_frame->method_code->code[curr_frame->pc + 1];
        shift = (shift << 8 ) | curr_frame->method_code->code[curr_frame->pc + 2];
        curr_frame->pc += shift;
    } else {
        curr_frame->pc +=3;
    }
}

void ifle(Frame *curr_frame) {
    Operand *op = curr_frame->pop_operand();
    int val = (int)op->type_int;

    if (val <= 0) {
        int shift;
        shift = curr_frame->method_code->code[curr_frame->pc + 1];
        shift = (shift << 8 ) | curr_frame->method_code->code[curr_frame->pc + 2];
        curr_frame->pc += shift;
    } else {
        curr_frame->pc +=3;
    }
}

/**
 * @brief Compara valor1 = valor2. Se verdeiro, realiza salto
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void if_icmpeq(Frame *curr_frame) {
    Operand *operand_1 = curr_frame->pop_operand();
    Operand *operand_2 = curr_frame->pop_operand();

    u4 value_operand_1 = operand_1->type_int;
    u4 value_operand_2 = operand_2->type_int;

    if(value_operand_2 == value_operand_1) {
        u2 offset;

        offset = curr_frame->method_code->code[curr_frame->pc + 1];
        offset = (offset << 8 ) | curr_frame->method_code->code[curr_frame->pc + 2];

        curr_frame->pc += offset;
    }else{
        curr_frame->pc +=3;
    }
}

/**
 * @brief Verifica se valor1 é diferente de valor2. Se for, realiza salto
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void if_icmpne(Frame *curr_frame) {
    Operand *op1 = curr_frame->pop_operand();
    Operand *op2 = curr_frame->pop_operand();

    u4 value_op1 = op1->type_int;
    u4 value_op2 = op2->type_int;

    if(value_op2 != value_op1) {
        int16_t offset;

        offset = curr_frame->method_code->code[curr_frame->pc + 1];
        offset = (offset << 8 ) | curr_frame->method_code->code[curr_frame->pc + 2];

        curr_frame->pc += offset;
    }else{
        curr_frame->pc +=3;
    }
}

void if_icmplt(Frame *curr_frame) {
    Operand *op1 =curr_frame->pop_operand();
    Operand *op2 =curr_frame->pop_operand();

    int value = op1->type_int;
    int value2 = op2->type_int;

    if(value2 < value) {
        int shift;

        shift =curr_frame->method_code->code[curr_frame->pc + 1];
        shift = (shift << 8 ) |curr_frame->method_code->code[curr_frame->pc + 2];

       curr_frame->pc += shift;
    }else{
       curr_frame->pc +=3;
    }
}

/**
 * @brief Salta para outro endereço caso  parametro 1 for maior ou igual ao parametro 2
 * @param Frame *curr_frame ponteiro que aponta para o frame atual
 * @return void
 */
void if_icmpge(Frame *curr_frame) {
    Operand *op1 = curr_frame->pop_operand();
    Operand *op2 = curr_frame->pop_operand();

    u4 value_param2 = op1->type_int;
    u4 value_param1 = op2->type_int;

    if (value_param1 >= value_param2) {
        u2 jump;

        jump = curr_frame->method_code->code[curr_frame->pc + 1];
        jump = (jump << 8 ) | curr_frame->method_code->code[curr_frame->pc + 2];

        curr_frame->pc += jump;
    }else{
        curr_frame->pc +=3;
    }
}

void if_icmpgt(Frame *curr_frame) {
  Operand *op1 =curr_frame->pop_operand();
  Operand *op2 =curr_frame->pop_operand();

  int value = op1->type_int;
  int value2 = op2->type_int;

  if(value2 > value) {
      int shift;

      shift =curr_frame->method_code->code[curr_frame->pc + 1];
      shift = (shift << 8 ) | curr_frame->method_code->code[curr_frame->pc + 2];

     curr_frame->pc += shift;
  }else{
     curr_frame->pc +=3;
  }
}

void if_icmple(Frame *curr_frame) {
  Operand *op1 =curr_frame->pop_operand();
  Operand *op2 =curr_frame->pop_operand();

  int value = op1->type_int;
  int value2 = op2->type_int;

  if(value2 <= value) {
      int shift;

      shift =curr_frame->method_code->code[curr_frame->pc + 1];
      shift = (shift << 8 ) | curr_frame->method_code->code[curr_frame->pc + 2];

     curr_frame->pc += shift;
  }else{
     curr_frame->pc +=3;
  }
}

void if_acmpeq(Frame *curr_frame) {
  u2 branch = curr_frame->method_code->code[curr_frame->pc + 1];
  branch = (branch << 8) + curr_frame->method_code->code[curr_frame->pc + 2];

  Operand *op = curr_frame->pop_operand();
  Operand *op2 = curr_frame->pop_operand();

  if (op->class_loader == op2->class_loader) {
      curr_frame->pc += branch;
  }
  else{
      curr_frame->pc += 3;
  }
}

void if_acmpne(Frame *curr_frame) {
  u2 branch = curr_frame->method_code->code[curr_frame->pc + 1];
  branch = (branch << 8) + curr_frame->method_code->code[curr_frame->pc + 2];

  Operand *op = curr_frame->pop_operand();
  Operand *op2 = curr_frame->pop_operand();

  if (op->class_loader != op2->class_loader) {
      curr_frame->pc += branch;
  }
  else{
      curr_frame->pc += 3;
  }
}

/*************************** CONTROL ***************************/

/**
 * @brief Função para saltar para um certo offset.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void ins_goto(Frame *curr_frame) {
    int16_t offset = curr_frame->method_code->code[curr_frame->pc+1];
    offset = (offset << 8) + curr_frame->method_code->code[curr_frame->pc+2];
    curr_frame->pc +=offset;
}

void ret(Frame *curr_frame) {
  u1 index = curr_frame->method_code->code[curr_frame->pc + 1];
  curr_frame->pc = curr_frame->local_variables_array[index]->type_int;
}

/**
 * @brief Acessa tabela de salto por chave e realizar salto.
 * @param Frame *curr_frame ponteiro que aponta para o frame atual
 * @return void
 */
void tableswitch(Frame *curr_frame){
    if (DEBUG) cout << "tableswitch\n";
    uint32_t dftByte = 0;
    uint32_t byteL = 0;
    uint32_t byteH = 0;
    uint32_t *jpOffset;
    uint32_t index;
    Operand *value1 = curr_frame->pop_operand();
    index = value1->type_int;
    uint32_t strt = curr_frame->pc;
    curr_frame->pc++;

    while (curr_frame->pc % 4 != 0) {
        curr_frame->pc++;
    }

    dftByte = curr_frame->method_code->code[curr_frame->pc++];
    dftByte = (dftByte << 8) + curr_frame->method_code->code[curr_frame->pc++];
    dftByte = (dftByte << 8) + curr_frame->method_code->code[curr_frame->pc++];
    dftByte = (dftByte << 8) + curr_frame->method_code->code[curr_frame->pc++];

    byteL = curr_frame->method_code->code[curr_frame->pc++];
    byteL = (byteL << 8) + curr_frame->method_code->code[curr_frame->pc++];
    byteL = (byteL << 8) + curr_frame->method_code->code[curr_frame->pc++];
    byteL = (byteL << 8) + curr_frame->method_code->code[curr_frame->pc++];

    byteH = curr_frame->method_code->code[curr_frame->pc++];
    byteH = (byteH << 8) + curr_frame->method_code->code[curr_frame->pc++];
    byteH = (byteH << 8) + curr_frame->method_code->code[curr_frame->pc++];
    byteH = (byteH << 8) + curr_frame->method_code->code[curr_frame->pc++];

    jpOffset = (uint32_t*)malloc((byteH - byteL + 1) * sizeof(uint32_t));

    for (int i = 0; i < (int)(byteH - byteL + 1); i++) {
        jpOffset[i] = curr_frame->method_code->code[curr_frame->pc++];
        jpOffset[i] = (jpOffset[i] << 8) + curr_frame->method_code->code[curr_frame->pc++];
        jpOffset[i] = (jpOffset[i] << 8) + curr_frame->method_code->code[curr_frame->pc++];
        jpOffset[i] = (jpOffset[i] << 8) + curr_frame->method_code->code[curr_frame->pc++];
    }

    if ((int32_t)index < (int32_t)byteL || (int32_t)index >(int32_t)byteH) {
        curr_frame->pc = strt + (int32_t)dftByte;
    }
    else {
        curr_frame->pc = strt + (int32_t)jpOffset[index - byteL];
    }

    free(jpOffset);
    if (DEBUG) cout << "tableswitch\n";
}

/**
 * @brief Acessa tabela de salto por chave e realiza salto.
 * @param Frame *curr_frame ponteiro que aponta para o frame atual
 * @return void
 */
void lookupswitch(Frame *curr_frame) {
    u4 dftByte = 0;
    u4 nPares = 0;
    u4 *jpKeys;
    u4 *jpOffset;
    u4 key;
    u4 start = curr_frame->pc;

    Operand *value_1 = curr_frame->pop_operand();
    key = value_1->type_int;
    curr_frame->pc++;

    while (curr_frame->pc % 4 != 0) {
        curr_frame->pc++;
    }

    dftByte = curr_frame->method_code->code[curr_frame->pc++];
    dftByte = (dftByte << 8) + curr_frame->method_code->code[curr_frame->pc++];
    dftByte = (dftByte << 8) + curr_frame->method_code->code[curr_frame->pc++];
    dftByte = (dftByte << 8) + curr_frame->method_code->code[curr_frame->pc++];

    nPares = curr_frame->method_code->code[curr_frame->pc++];
    nPares = (nPares << 8) + curr_frame->method_code->code[curr_frame->pc++];
    nPares = (nPares << 8) + curr_frame->method_code->code[curr_frame->pc++];
    nPares = (nPares << 8) + curr_frame->method_code->code[curr_frame->pc++];

    jpKeys = (u4*)malloc(nPares * sizeof(u4));
    jpOffset = (u4*)malloc(nPares * sizeof(u4));
    for (int i = 0; i < (int)nPares; i++) {
        jpKeys[i] = curr_frame->method_code->code[curr_frame->pc++];
        jpKeys[i] = (jpKeys[i] << 8) + curr_frame->method_code->code[curr_frame->pc++];
        jpKeys[i] = (jpKeys[i] << 8) + curr_frame->method_code->code[curr_frame->pc++];
        jpKeys[i] = (jpKeys[i] << 8) + curr_frame->method_code->code[curr_frame->pc++];

        jpOffset[i] = curr_frame->method_code->code[curr_frame->pc++];
        jpOffset[i] = (jpOffset[i] << 8) + curr_frame->method_code->code[curr_frame->pc++];
        jpOffset[i] = (jpOffset[i] << 8) + curr_frame->method_code->code[curr_frame->pc++];
        jpOffset[i] = (jpOffset[i] << 8) + curr_frame->method_code->code[curr_frame->pc++];
    }

    int i;
    for (i = 0; i < (int)nPares; ++i) {
        if (jpKeys[i] == key) {
            curr_frame->pc = start + jpOffset[i];
            break;
        }
    }
    if ((unsigned)i == nPares)
        curr_frame->pc = start + dftByte;

    free(jpKeys);
    free(jpOffset);
}

/**
 * @brief Retorna int de um método.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void ireturn(Frame *curr_frame) {
    curr_frame->pc++;
    Operand *integer = curr_frame->pop_operand();
    pop_frame();
    Frame *called_frame = top_frame();
    called_frame->push_operand(integer);
}

/**
 * @brief Retorna long int de um método.
 * @param Frame *curr_frame ponteiro que aponta para o frame atual
 * @return void
 */
void lreturn(Frame *curr_frame) {
    curr_frame->pc++;
    Operand *long_value = curr_frame->pop_operand();
    pop_frame();
    Frame *past_frame = top_frame();
    past_frame->push_operand(long_value);
}

/**
 * @brief Retorna float de um método.
 * @param Frame *curr_frame ponteiro o frame atual
 * @return void
 */
void freturn(Frame *curr_frame) {
    curr_frame->pc++;
    Operand *float_value = curr_frame->pop_operand();
    pop_frame();
    Frame *called_frame = top_frame();
    called_frame->push_operand(float_value);
}

/**
 * @brief Retorna double de um método.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void dreturn(Frame *curr_frame) {
    curr_frame->pc++;
    Operand *double_value = curr_frame->pop_operand();
    pop_frame();
    Frame *called_frame = top_frame();
    called_frame->push_operand(double_value);
}

/**
 * @brief Retorna objeto de um método.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void areturn(Frame *curr_frame) {
    curr_frame->pc++;
    Operand *object = curr_frame->pop_operand();
    pop_frame();
    Frame *called_frame = top_frame();
    called_frame->push_operand(object);
}

/**
* @brief Retorna void de uma instrução.
* @param *curr_frame ponteiro para o frame atual
* @return void
*/
void void_return(Frame *curr_frame) {
    curr_frame->pc++;
    pop_frame();
}

/*************************** REFERENCES ***************************/

/**
 * @brief Recebe um campo estático a partir de uma classe.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void getstatic(Frame *curr_frame) {
    if (DEBUG) cout << "----------getstatic----------\n";

    curr_frame->pc++;

    u2 index = curr_frame->method_code->code[curr_frame->pc++];
    index = (index << 8) + curr_frame->method_code->code[curr_frame->pc++];

    Cp_Info &field_info = curr_frame->cp_reference[index];
    Cp_Info &name_and_type = curr_frame->cp_reference[field_info.Fieldref.name_and_type_index];
    // string class_name = get_cp_info_utf8(*(curr_frame->class_file_ref), field_info.Fieldref.class_index);
    string class_name = get_utf8_constant_pool(curr_frame->cp_reference, field_info.Fieldref.class_index);

    // se for a classe default do Java: System -> nao empilhar
    if (class_name == "java/lang/System") {
      if (DEBUG) cout << "Java Default Class: java/lang/System" << "\n";
      return;
    }

    Class_File class_file = get_class_info_and_load_not_exists(class_name);
    string var_name = get_cp_info_utf8(class_file, name_and_type.NameAndType.name_index);
    Operand *static_field = get_static_field_of_class(class_name, var_name);

    curr_frame->push_operand(static_field);
}

/** @brief ...
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void getfield(Frame *curr_frame) {
  u1 byte1 = curr_frame->method_code->code[curr_frame->pc++];
  u1 byte2 = curr_frame->method_code->code[curr_frame->pc++];

  u2 index = (byte1 << 8) | byte2;

  Cp_Info field_ref = curr_frame->cp_reference[index];
  Cp_Info name_and_type = curr_frame->cp_reference[field_ref.Fieldref.class_index];

  string class_name = get_utf8_constant_pool(curr_frame->cp_reference, field_ref.Fieldref.class_index);
  string field_name = get_utf8_constant_pool(curr_frame->cp_reference, name_and_type.NameAndType.name_index);

  curr_frame->operand_stack.pop();

  // curr_frame->push_operand(classVariable);
}

/**
 * @brief ...
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void putfield(Frame *curr_frame) {
    curr_frame->pc++;

    u2 index = curr_frame->method_code->code[curr_frame->pc++];
    index = (index<<8) + curr_frame->method_code->code[curr_frame->pc++];
    Cp_Info field_reference = curr_frame->cp_reference[index];

    Cp_Info name_and_type = curr_frame->cp_reference[field_reference.Fieldref.class_index];

    string class_name = get_utf8_constant_pool(curr_frame->cp_reference, field_reference.Fieldref.class_index);
    string var_name = get_utf8_constant_pool(curr_frame->cp_reference, name_and_type.NameAndType.name_index);

    Operand *var_operand = curr_frame->pop_operand();
    Operand *class_instance = curr_frame->pop_operand();

    Operand *class_variable = class_instance->class_loader->class_fields->at(var_name);

    switch (var_operand->tag) {
        case CONSTANT_INT:
            class_variable->type_int = var_operand->type_int;
            break;
        case CONSTANT_LONG:
            class_variable->type_long = var_operand->type_long;
            break;
        case CONSTANT_BOOL:
            class_variable->type_bool = var_operand->type_bool;
            break;
        case CONSTANT_CHAR:
            class_variable->type_char = var_operand->type_char;
            break;
        case CONSTANT_SHORT:
            class_variable->type_short = var_operand->type_short;
            break;
        case CONSTANT_BYTE:
            class_variable->type_byte = var_operand->type_byte;
            break;
        case CONSTANT_FLOAT:
            class_variable->type_float = var_operand->type_float;
            break;
        case CONSTANT_DOUBLE:
            class_variable->type_double = var_operand->type_double;
            break;
        case CONSTANT_STRING:
            class_variable->type_string = var_operand->type_string;
            break;
        case CONSTANT_CLASS:
            class_variable->class_loader = var_operand->class_loader;
            break;
        case CONSTANT_ARRAY:
            class_variable->array_type = var_operand->array_type;
            break;
    }
}

/**
 * @brief Invoca instância de método baseado na classe.
 * @param *curr_frame ponteiro que aponta para o frame atual
 * @return void
 */
void invokevirtual(Frame *curr_frame) {
  if (DEBUG) cout << "----------invokevirtual----------\n";
  curr_frame->pc++;

  u2 index = curr_frame->method_code->code[curr_frame->pc] << 16;
  index += curr_frame->method_code->code[++curr_frame->pc];
  curr_frame->pc++;

  Cp_Info &method_ref = curr_frame->cp_reference[index];
  Cp_Info &name_and_type = curr_frame->cp_reference[method_ref.Methodref.name_and_type_index];

  // * Utilizando o Cp_Info
  string class_name = get_utf8_constant_pool(curr_frame->cp_reference, method_ref.Methodref.class_index);
  string method_name = get_utf8_constant_pool(curr_frame->cp_reference, name_and_type.NameAndType.name_index);
  string method_desc = get_utf8_constant_pool(curr_frame->cp_reference, name_and_type.NameAndType.descriptor_index);

  if (strstr(class_name.c_str(), "java/")) {
    if (class_name == "java/io/PrintStream" && (method_name == "println" || method_name == "print")) {
      if (method_desc != "()V") {
        if (DEBUG) cout << "CHEGOU AQUI - java/io/PrintStream\n";
        Operand *op = curr_frame->pop_operand();

        switch(op->tag) {
          case CONSTANT_BYTE:
              if (DEBUG) cout << "CONSTANT_BYTE: ";
              cout << (int) op->type_byte;
              break;
          case CONSTANT_CHAR:
              if (DEBUG) cout << "CONSTANT_CHAR: ";
              cout << (char) op->type_char;
              break;
          case CONSTANT_SHORT:
              if (DEBUG) cout << "CONSTANT_SHORT: ";
              cout << (short) op->type_short;
              break;
          case CONSTANT_BOOL:
              if (DEBUG) cout << "CONSTANT_BOOL: ";
              cout << (bool) op->type_bool;
              break;
          case CONSTANT_STRING:
              if (DEBUG) cout << "CONSTANT_STRING: ";
              cout << *op->type_string;
              break;
          case CONSTANT_INT:
              if (DEBUG) cout << "CONSTANT_INT: ";
              cout << (u4) op->type_int;
              break;
          case CONSTANT_FLOAT: {
              float float_v;
              memcpy(&float_v, &op->type_float, sizeof(float));
              if (DEBUG) cout << "CONSTANT_FLOAT: ";
              printf("%f", float_v); }
              break;
          case CONSTANT_LONG:
              if (DEBUG) cout << "CONSTANT_LONG: ";
              cout << (long) op->type_long;
              break;
          case CONSTANT_DOUBLE: {
              double double_v;
              memcpy(&double_v, &op->type_double, sizeof(double));
              if (DEBUG) cout << "CONSTANT_DOUBLE: ";
              printf("%.15lf", double_v); }
              break;
          case CONSTANT_EMPTY:
              printf("null");
              break;
          case CONSTANT_CLASS: {
              Class_Loader *class_loader = op->class_loader;
              Class_File class_file = class_loader->class_file;
              string this_class_name = get_cp_info_utf8(class_file, class_file.this_class);
              cout << this_class_name << "@" << class_loader;
          }
          break;
        }
        if (method_name == "println") {
          printf("\n");
        }
      }
    } else if (class_name == "java/lang/String" && method_name == "length") {
        if (DEBUG) cout << "CHEGOU AQUI - java/lang/String\n";

        Operand *str_ref = curr_frame->pop_operand();

        Operand *str_len = (Operand*) malloc(sizeof(Operand));
        str_len->tag = CONSTANT_INT;
        str_len->type_int = str_ref->type_string->size();
        curr_frame->push_operand(str_len);

    } else if (class_name == "java/lang/StringBuilder" && method_name == "append") {
        if (DEBUG) cout << "CHEGOU AQUI - java/lang/StringBuilder\n";

        Operand *t_append = curr_frame->pop_operand();
        Operand *str_append = copy_operand(curr_frame->pop_operand());

        switch (t_append->tag) {
            case CONSTANT_STRING:
                *str_append->type_string += (*t_append->type_string);
                break;
            case CONSTANT_INT:
                *str_append->type_string += (
                                    patch::to_string(t_append->type_int));
                break;
            case CONSTANT_LONG:
                *str_append->type_string += (
                                    patch::to_string(t_append->type_long));
                break;
            case CONSTANT_FLOAT:
                *str_append->type_string += (
                                  patch::to_string(t_append->type_float));
                break;
            case CONSTANT_DOUBLE:
                *str_append->type_string += (
                                  patch::to_string(t_append->type_double));
                break;
            case CONSTANT_SHORT:
                *str_append->type_string += (
                                    patch::to_string(t_append->type_short));
                break;
            case CONSTANT_CHAR:
                *str_append->type_string += (
                                    patch::to_string(t_append->type_char));
                break;
            case CONSTANT_BYTE:
                *str_append->type_string += (
                                    patch::to_string(t_append->type_byte));
                break;
            case CONSTANT_BOOL:
                if (t_append->type_bool == 0)
                    *str_append->type_string += "false";
                else
                    *str_append->type_string += "true";
                break;
            case CONSTANT_CLASS:
                // @TODO colocar enderec
                *str_append->type_string += *t_append->class_loader->class_name+"@";
                break;
            case CONSTANT_ARRAY:
                *str_append->type_string += "Array[]";
                break;
        }
        curr_frame->push_operand(str_append);
    } else if (class_name == "java/lang/StringBuilder") {
      // ignorando o toString;
      return;
    }
  } else {
      int qtde_arg = 0;
      u2 counter = 1;

      while (method_desc[counter] != ')') {
          char found_type = method_desc[counter];
          if (found_type == 'L') { // tipo é um objeto
              qtde_arg++;
              while (method_desc[++counter] != ';');

          } else if (found_type == '[') { // tipo é um array?
              qtde_arg++;
              while (method_desc[++counter] == '[');

              if (method_desc[counter] == 'L')
                  while (method_desc[++counter] != ';');
          } else qtde_arg++;
          counter++;
      }
      std::vector<Operand*> args;

    for (int i = 0; i < qtde_arg; ++i) {
      Operand *arg = curr_frame->pop_operand();
      args.insert(args.begin(), arg);
      if (arg->tag == CONSTANT_DOUBLE || arg->tag == CONSTANT_LONG)
          args.insert(args.begin()+1, check_string_create_type("P"));
    }

    Operand *current_class = curr_frame->pop_operand();
    args.insert(args.begin(), current_class);

    Class_Loader *class_loader = current_class->class_loader;

    Method_Info *method_info = find_method(class_loader->class_file, method_name, method_desc);
    Frame *new_frame = new Frame(method_info, (class_loader->class_file));

    for (int j = 0; (unsigned)j < args.size(); ++j)
        new_frame->local_variables_array.at(j) = args.at(j);

    push_frame(new_frame);
  }
}

/**
* @brief Invoca o método de instância, e trata da inicialiação da superclasse
* @param *curr_frame ponteiro para o frame atual
* @return void
*/
void invokespecial(Frame *curr_frame) {
  if (DEBUG) cout << "----------invokespecial----------\n";

	//incrementa pc
	curr_frame->pc++;

	u2 index_method = curr_frame->method_code->code[curr_frame->pc];
	index_method = (index_method << 8) + curr_frame->method_code->code[++curr_frame->pc];

	Cp_Info &ref_method = curr_frame->cp_reference[index_method];
	Cp_Info &name_and_type = curr_frame->cp_reference[ref_method.Methodref.name_and_type_index];

  string class_name = get_utf8_constant_pool(curr_frame->cp_reference, ref_method.Methodref.class_index);
	string method_name = get_utf8_constant_pool(curr_frame->cp_reference, name_and_type.NameAndType.name_index);
	string method_descriptor = get_utf8_constant_pool(curr_frame->cp_reference, name_and_type.NameAndType.descriptor_index);

  //incrementa pc
	curr_frame->pc++;

	if ( ((class_name == "java/lang/Object" || class_name == "java/lang/String")
      && method_name == "<init>") ||
		(class_name == "java/lang/StringBuilder" && method_name == "<init>")) {
		if (class_name == "java/lang/String" ||
        class_name == "java/lang/StringBuilder") {
			curr_frame->pop_operand();
		}
		else if (method_name == "<init>") {
			Operand *variable_class = curr_frame->local_variables_array.at(0);
			load_class_var(variable_class->class_loader);
		}
		return;

    } else if (class_name.find("java/") != string::npos) {
        printf("Classe java nao implementada.");
        getchar();
        exit(1); // caso seja algum outro tipo de classe java nao implementada
    } else {
        int count_args = 0;
        u2 counter = 1;

        while (method_descriptor[counter] != ')') {
            char created_type = method_descriptor[counter];
            if (created_type == 'L') { // tipo é um objeto
                count_args++;
                while (method_descriptor[++counter] != ';');
            } else if (created_type == '[') {
                count_args++;
                while (method_descriptor[++counter] == '[');
                if (method_descriptor[counter] == 'L')
                    while (method_descriptor[++counter] != ';');
            } else count_args++;
            counter++;
        }
        std::vector<Operand*> arguments;

        for (int i = 0; i < count_args; ++i) {
            Operand *argument = curr_frame->pop_operand();
            arguments.insert(arguments.begin(), argument);
            if (argument->tag == CONSTANT_DOUBLE ||
                argument->tag == CONSTANT_LONG) {
                arguments.insert(arguments.begin()+1, check_string_create_type("P"));
            }
        }

        Operand *current_class = curr_frame->pop_operand();
        arguments.insert(arguments.begin(), current_class);

        Class_Loader *reference_class = current_class->class_loader;

        Method_Info *method_info_found = find_method(reference_class->class_file, method_name, method_descriptor);
        Frame *new_frame = new Frame(method_info_found, reference_class->class_file);

        for (int j = 0; (unsigned)j < arguments.size(); ++j)
            new_frame->local_variables_array.at(j) = arguments.at(j);

        push_frame(new_frame);
    }
}

/**
 * @brief Invoca um método estático de uma classe.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void invokestatic(Frame *curr_frame) {
  if (DEBUG) cout << "----------invokestatic----------\n";

  curr_frame->pc++;

  u2 method_index = curr_frame->method_code->code[curr_frame->pc++];
  method_index = (method_index << 8) + curr_frame->method_code->code[curr_frame->pc++];

  Cp_Info &method_info = curr_frame->cp_reference[method_index];
  Cp_Info &class_info = curr_frame->cp_reference[method_info.Methodref.class_index];

  string class_name = get_utf8_constant_pool(curr_frame->cp_reference, class_info.Class.class_name);

  Cp_Info &name_and_type = curr_frame->cp_reference[
                                  method_info.Methodref.name_and_type_index];

  string method_name = get_utf8_constant_pool(curr_frame->cp_reference, name_and_type.NameAndType.name_index);

  if (DEBUG) cout << "nome do metodo a ser chamado: " << method_name << "\n";

  string method_descriptor = get_utf8_constant_pool(curr_frame->cp_reference,name_and_type.NameAndType.descriptor_index);

  if (DEBUG) cout << "nome da classe: " << class_name << "\n";
  if (class_name == "java/lang/Object" && method_name == "registerNatives") {
    printf("JVM não suporta método nativo.");
    return;
  }
  // calcula quantos argumentos o metodo tem
  int count_arguments = 0;
  u2 counter = 1;
  while (method_descriptor[counter] != ')') {
      char find_type = method_descriptor[counter];

      if (find_type == 'L') { // tipo objeto
          count_arguments++;
          while (method_descriptor[++counter] != ';');
      } else if (find_type == '[') { // tipo array
          count_arguments++;
          while (method_descriptor[++counter] == '[');
          if (method_descriptor[counter] == 'L')
              while(method_descriptor[++counter] != ';');
      } else count_arguments++;
      counter++;
  }

  if (DEBUG) cout << "metodo possui " << count_arguments << " argumentos\n";

  // não precisa criar frame para definir tipo float
  if (class_name.find("Float") != string::npos &&
      method_name.find("valueOf") != string::npos) {
        if (DEBUG) cout << "ignorar Float.valueOf\n";
        return;
  } else {
    std::vector<Operand*> arguments;

    if (DEBUG) cout << "passando argumentos para o metodo estatico\n";
    for (int i = 0; i < count_arguments; ++i) {
        Operand *argument = curr_frame->pop_operand();
        if (DEBUG) cout << "operando do tipo: " <<  (int)argument->tag << "\n";

        // passa argumento para a função
        arguments.insert(arguments.begin(), argument);
        if (argument->tag == CONSTANT_DOUBLE || argument->tag == CONSTANT_LONG)
            arguments.insert(arguments.begin() + 1,
                            check_string_create_type("P"));
    }

    Class_Loader *class_loader = get_static_class(class_name);
    Method_Info *method_finded = find_method(class_loader->class_file, method_name, method_descriptor);
    Frame *new_frame = new Frame(method_finded, class_loader->class_file);

    // vetor das variáveis locais
    for (int j = 0; (unsigned)j < arguments.size(); ++j)
        new_frame->local_variables_array.at(j) = arguments.at(j);

    push_frame(new_frame);
  }
}

/** @brief Invoca a interface do método.
@param Frame *curr_frame ponteiro que aponta para o frame atual
@return void
*/
void invokeinterface(Frame *curr_frame) {
  if (DEBUG) cout << "----------invokeinterface----------\n";

  curr_frame->pc++;

  u2 method_index = curr_frame->method_code->code[curr_frame->pc++];
  method_index = (method_index << 8) + curr_frame->method_code->code[curr_frame->pc++];

  Cp_Info &method_info = curr_frame->cp_reference[method_index];

  Cp_Info &class_info = curr_frame->cp_reference[method_info.Methodref.class_index];
  string class_name = get_utf8_constant_pool(curr_frame->cp_reference, class_info.Class.class_name);

  Cp_Info &name_and_type = curr_frame->cp_reference[method_info.Methodref.name_and_type_index];
  string method_name = get_utf8_constant_pool(curr_frame->cp_reference, name_and_type.NameAndType.name_index);
  string method_descriptor = get_utf8_constant_pool(curr_frame->cp_reference, name_and_type.NameAndType.descriptor_index);
}

/**
 * @brief Cria novo array podendo ser de qualquer tipo.
 * @param Frame *curr_frame ponteiro que aponta para o frame atual
 * @return void
 */
void new_obj(Frame *curr_frame) {
    curr_frame->pc++;
    u2 index = curr_frame->method_code->code[curr_frame->pc];
    index = (index << 8)+curr_frame->method_code->code[++curr_frame->pc];

    Cp_Info &class_info = curr_frame->cp_reference[index];
    string utf8_constant = get_utf8_constant_pool(curr_frame->cp_reference, class_info.Class.class_name);


    if (utf8_constant == "java/lang/StringBuilder") {
        Operand* string_builder = (Operand*)malloc(sizeof(Operand));
        string_builder->tag = CONSTANT_STRING;
        string_builder->type_string = new string("");
        curr_frame->push_operand(string_builder);
    }else{
        Operand *instance = check_string_create_type("L" + utf8_constant);
        curr_frame->push_operand(instance);
    }
    curr_frame->pc++;
}

/**
 * @brief Cria novo array do tipo definido
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void newarray(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  u4 index = operand_1->type_int;

  Operand *operand_2 = check_string_create_type("[");
  u1 array_type = curr_frame->method_code->code[curr_frame->pc++];

  switch ((int)array_type) {
    case 4:
      for (int i = 0; i < (int) index; i++) {
        operand_2->array_type->array->emplace_back(check_string_create_type("Z"));
      }
      break;
    case 5:
      for (int i = 0; i < (int) index; i++) {
        operand_2->array_type->array->emplace_back(check_string_create_type("C"));
      }
      break;
    case 6:
      for (int i = 0; i < (int) index; i++) {
        operand_2->array_type->array->emplace_back(check_string_create_type("F"));
      }
      break;
    case 7:
      for (int i = 0; i < (int) index; i++) {
        operand_2->array_type->array->emplace_back(check_string_create_type("D"));
      }
      break;
    case 8:
      for (int i = 0; i < (int) index; i++) {
        operand_2->array_type->array->emplace_back(check_string_create_type("B"));
      }
      break;
    case 9:
      for (int i = 0; i < (int) index; i++) {
        operand_2->array_type->array->emplace_back(check_string_create_type("S"));
      }
      break;
    case 10:
      if (DEBUG) cout << "array type int\n";
      for (int i = 0; i < (int) index; i++)
        operand_2->array_type->array->emplace_back(check_string_create_type("I"));
      break;
    case 11:
      if (DEBUG) cout << "array type long\n";
      for (int i = 0; i < (int) index; i++)
        operand_2->array_type->array->emplace_back(check_string_create_type("J"));
      break;
  }

  if (DEBUG) cout << "array size "
                      << operand_2->array_type->array->size() << "\n";

  curr_frame->push_operand(operand_2);

  if (DEBUG) cout << "newarray\n";
}

/**
 * @brief Cria novo objeto array.
 * @param *curr_frame Ponteiro para o frame atual
 * @return void
 */
void anewarray(Frame *curr_frame) {}

void arraylength(Frame* curr_frame) {
  curr_frame->pc++;

  Operand *array = curr_frame->pop_operand();

  Operand *size = check_string_create_type("I");
  size->type_int = array->array_type->array->size();
  curr_frame->push_operand(size);
}

/*************************** EXTENDED ***************************/

void ifnull(Frame *curr_frame) {
    Operand *operand = curr_frame->pop_operand();

    if (!(operand->type_int)) {
        int shift;
        shift = curr_frame->method_code->code[curr_frame->pc + 1];
        shift = (shift << 8 ) | curr_frame->method_code->code[curr_frame->pc + 2];
        curr_frame->pc += shift;
    } else {
        curr_frame->pc +=3;
    }
}

void ifnonnull(Frame *curr_frame) {
    Operand *operand = curr_frame->pop_operand();

    if (operand->type_int) {
        int shift;
        shift = curr_frame->method_code->code[curr_frame->pc + 1];
        shift = (shift << 8 ) | curr_frame->method_code->code[curr_frame->pc + 2];
        curr_frame->pc += shift;
    } else {
        curr_frame->pc +=3;
    }
}
