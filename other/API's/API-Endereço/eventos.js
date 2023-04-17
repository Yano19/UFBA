const INPUT_cep = document.getElementById('cep');
const INPUT_logradouro = document.getElementById('logradouro');
const INPUT_numero = document.getElementById('numero');
const INPUT_bairro = document.getElementById('bairro');
const INPUT_cidade = document.getElementById('cidade');
const INPUT_uf = document.getElementById('uf');

INPUT_cep.addEventListener('blur', () => {
    let cep = INPUT_cep.value;
    if (cep.length !== 8) {
        return;
    }

    fetch(`https://viacep.com.br/ws/${cep}/json/`)
        .then(response => response.json()) //ao pegar a resposta, me retorne apenas o JSON (conteudo)
        .then(json => {
            INPUT_logradouro.value = json.logradouro;
            INPUT_bairro.value = json.bairro;
            INPUT_cidade.value = json.localidade;
            INPUT_uf.value = json.uf;

            INPUT_numero.focus(); // ao terminar de digitaar o cep, irá redirecionar para o form do número
        });
})