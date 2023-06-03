var tab = document.getElementById('tab').getElementsByTagName('li');
var dis = document.getElementById('seckill-body').getElementsByTagName('ul');

for(var i=0;i<tab.length;i++){
    tab[i].onclick = show;
    dis[i].onclick = show;
}

function show(){
    for(var i=0;i<tab.length;i++){
        if(tab[i]===this){
            tab[i].className='active';
            dis[i].className='play';
        }
        else{
            
            tab[i].className='';
            dis[i].className='';
        }
    }
}
