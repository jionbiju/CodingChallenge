

let name="ELSA";

function outerfuction(){
    let outervar = "inside outerfuction";
    function innerfuction(){
        let inner_var="inside innerfuction";
        console.log(name);
        console.log(inner_var);
        console.log(outervar);
    }
    innerfuction();
}
outerfuction();