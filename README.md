- Refatoração de Código Legado — Gilded Rose Kata (C)

Atividade prática da disciplina de **Engenharia de Software** com foco na análise, cobertura de testes unitários e refatoração de código legado aplicando princípios de *Clean Code*.

-- Sobre o Projeto
O sistema gerencia o estoque diário da pousada *Gilded Rose*, atualizando o prazo de venda (`sellIn`) e a qualidade (`quality`) de diferentes categorias de itens conforme suas regras específicas:
- **Itens Comuns:** perdem qualidade diariamente (e duas vezes mais rápido após o vencimento).
- **Aged Brie:** aumenta de qualidade com o passar do tempo.
- **Sulfuras:** item lendário que não sofre alterações de prazo ou qualidade.
- **Backstage passes:** aumentam de qualidade conforme a proximidade do evento e zeram após a data.
- **Conjured (nova funcionalidade):** degradam duas vezes mais rápido que os itens comuns.

## O que foi realizado
- **Diagnóstico e Correção Inicial:** resolução do conflito de assinatura da função `print_item` e correção de retorno para eliminar avisos (*warnings*) de compilação.
- **Testes Unitários (CppUTest):** criação de uma suíte de 13 testes automatizados cobrindo todas as regras legadas e os novos cenários de itens conjurados.
- **Refatoração (Clean Code):** extração das regras de negócio aninhadas em funções pequenas, coesas e auto-documentáveis em português, isolando cada tipo de item.

## Como compilar e executar os testes
No terminal (ambiente Linux/WSL com `CppUTest` instalado):

```bash
make
./GildedRoseUnitTests
```
