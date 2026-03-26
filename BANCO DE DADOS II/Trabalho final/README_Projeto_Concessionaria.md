# 🚗 Sistema de Banco de Dados -- Concessionária

Projeto desenvolvido para a disciplina **Banco de Dados** no curso de
**Engenharia de Software**.

## 📌 Objetivo

Desenvolver a modelagem de um banco de dados para gerenciar uma
**Concessionária de Veículos**, permitindo o controle de:

-   Clientes
-   Veículos
-   Fabricantes
-   Modelos
-   Vendedores
-   Concessionárias
-   Pedidos de venda

------------------------------------------------------------------------

# 🧠 Etapas do Projeto

## 1️⃣ Modelo Conceitual

Representação das entidades e relacionamentos do sistema através de
**Diagrama Entidade‑Relacionamento (ER)**.

Principais entidades:

-   Cliente
-   Veículo
-   Modelo
-   Fabricante
-   Vendedor
-   Concessionária
-   Pedido

------------------------------------------------------------------------

## 2️⃣ Modelo Lógico

Conversão do modelo conceitual para o modelo relacional, definindo:

-   Tabelas
-   Chaves primárias
-   Chaves estrangeiras
-   Relacionamentos

------------------------------------------------------------------------

## 3️⃣ Script SQL

Implementação da estrutura do banco de dados utilizando SQL.

Exemplo:

``` sql
CREATE TABLE Cliente (
    id_cliente INT PRIMARY KEY,
    nome VARCHAR(100),
    cpf VARCHAR(14),
    telefone VARCHAR(20),
    email VARCHAR(100),
    endereco VARCHAR(200)
);
```

------------------------------------------------------------------------

# 👨‍💻 Integrantes

-   Arthur Grizone
-   Gustavo Antonio
-   Leonardo Gambaroni
-   Lucas Xavier
-   Mateus Oliveira
-   Wanderley Vieira

------------------------------------------------------------------------

# 🛠 Tecnologias Utilizadas

-   SQL
-   Modelagem de Banco de Dados
-   brModelo

------------------------------------------------------------------------

📚 Projeto acadêmico desenvolvido para fins educacionais.
