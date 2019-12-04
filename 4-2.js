function checker(number){
    let str = String(number)
    let adjacent = false, c = false
    let repeats = 0;
    for(let it = 0; it < 5; ++it){
        if(str[it] > str[it+1] ) return false
        if(str[it] == str[it+1]){
            adjacent = true
            repeats = repeats*10 + it
        }
    }
    let rp = String(repeats)
    switch(rp.length){
        case 1:
            c = true
            break
        case 2:
            if(rp[0]+1 != rp[1]) c = true
            break
        default:
            for(let i = 1; i < rp.length; ++i){
                if(rp[i]+1 < rp[i+1] && rp[i-1]+1 < rp[i]) c = true
            }
    }
    return (c && adjacent)
}

let lower = prompt('input lower bound', 0)
let upper = prompt('input upper bound', 999999)
let counter = 0
for(let iterator = lower; iterator <= upper; ++iterator){
    if(checker(iterator)) ++counter
}
console.log('ctr: ' + counter)