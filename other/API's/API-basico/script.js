//fazer algo, ou seja, qual resposta obteve
//fetch retorna response e eu peço para que ela seja em json

function fetchapi(){
    fetch('https://jsonplaceholder.typicode.com/todos/')
    .then((response) => response.json())
    //exibir os dados no console
    //data é o response.json
    .then(data => {
       const list = document.querySelector('#SFILL_LIST'); 
       //map navega o data e retorna algo
       data.map((item) => {
        const li = document.createElement('li');
        li.setAttribute('id', item.id);
        //inserir todos os title que nós obtemos da nossa requisição
        li.innerHTML = item.title;
        list.appendChild(li);
       }) 
    })   
} 
