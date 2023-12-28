class ZjHashElem {

$(o) { return o; }

constructor(next, hash, key, data) {
    this.next = next;
    this.hash = hash;
    this.key = key;
    this.data = data;
}

dispose() {
    delete this.data;
    delete this;
}

}

class ZjHash {

$(o) { return o; }

static notset = "[null]";

constructor(size, dispose)
{
    this.size = Math.log2(size) << 1;
    this.mask = this.size - 1;
    this.disposeElem = dispose;
    this.table = new Array(this.size);
    for (let i = 0; i < this.size; i++) {
        this.table[i] = null;
    }
}

dispose()
{
    for (let i = 0; i < this.size; i++) {
        let el = this.table[i];
        while (el != null) {
            let next = el.next;
            if (this.disposeElem != null) {
                this.disposeElem(el.data);
            }
            el.dispose();
            el = next;
        }
    }
    delete this.table;
    delete this;
}

hash(k)
{
    let l = k.length;
    let h = 0;
    if (l > 0) {
        h = k.codePointAt(0);
    }
    let i = 1;
    while (i < l) {
        h = (h << 3) ^ k.codePointAt(i);
        i++;
    }
    return h;
}

add(k, val)
{
    let hhh = this.hash(k);
    let p = hhh & this.mask;
    let a = table[p];
    let r = null;

    if (a == null) {
        r = new ZjHashElem(null, hhh, k, val);
        table[p] = r;
    } else {
        let n = a;
        let prev = null;
        while (r == null && n != null) {
            if (n.hash == hhh) {
                let cmp = k.localeCompare(n.key);
                if (cmp > 0) {
                    r = new ZjHashElem(n, hhh, k, val);
                    if (prev == null) {
                        this.table[p] = r;
                    } else {
                        prev.next = r;
                    }
                    return;
                } else if (cmp == 0) {
                    if (this.disposeElem != null) {
                        this.disposeElem(n.data);
                    }
                    n.data = val;
                    return;
                }
            } else if (hhh > n.hash) {
                r = new ZjHashElem(n, hhh, k, val);
                if (prev == null) {
                    this.table[p] = r;
                } else {
                    prev.next = r;
                }
                return;
            }
            prev = n;
            if (n.next == null) {
                r = new ZjHashElem(null, hhh, k, val);
                n.next = r;
                return;
            }
            n = n.next;
        }
    }
}

get(k)
{
    let h = this.hash(k);
    let p = h & this.mask;
    let a = this.table[p];
    if (a == null) {
        return ZjHash.notset    ;
    }
    let n = a;
    while (n != null) {
        if (n.hash == h) {
            let cmp = k.localeCompare(n.key);
            if (cmp > 0) {
                return ZjHash.notset;
            }
            if (cmp == 0) {
                return n.data;
            }
        } else if (h > n.hash) {
            return ZjHash.notset;
        }
        n = n.next;
    }
    return ZjHash.notset;
}

}