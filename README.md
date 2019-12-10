# RSS-Feed
Feed de notícias - RSS criado para o trabalho final da matéria Programação de Computadores I

Nomes: Mateus de souza pequeno furtado de Mendonça, Breno Miguez, Marcos Souza

Para compilar basta ter, o executavél principal trab2main.c, e o arquivo xml baixado no seu pc, no caso, 
taguatinga.xml.

Escolhemos o RSS do IFB, Taguatinga, https://www.ifb.edu.br/taguatinga?start=10;&format=feed&type=rss
Devido ao fato de termos achado o site mais bem estruturado e simples dentro das informações com as quais 
trabalhariamos.

O código usa uma função principal que compara os elementos lidos do arquivo com uma string que 
definimos, logo todo o conteudo dentro dessa string que definimos como por ex: string [] = "<title>" vai ser usado 
quando formos montar o HTML, depois disso criamos diversas condições para impressão, com o objetivo de montar  HTML
de acordo com as especificações.
