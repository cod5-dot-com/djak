// main thread

const { contextBridge } = require('electron');
const fs = require("fs");
const os = require("os");

contextBridge.exposeInMainWorld("sendRequest", function (data, form, type, callback)
{
    let folder = form.elements["folder"].value;
    let func = form.elements["func"].value;
    let target = form.elements["target"].value;
    let size = form.elements["size"].value;
    let seek = form.elements["seek"].value;
    let files = form.elements["files"].value;
    let r = {status: 200, response: null};
    let enc = null;
    let d = null;
    let fd = 0;
    let tgt = os.homedir() + "/" + folder + "/" + target;

    switch(func) {
    case "mkfolder":
        d = Date();
        folder = "" + d.getUTCFullYear(); 
        if (d.getUTCMonth() < 9) {
            folder += "0" + (d.getUTCMonth() + 1);
        } else {
            folder += (d.getUTCMonth() + 1);
        }
        if (d.getUTCDate() < 10) {
            folder += "0" + d.getUTCDate();
        } else {
            folder += d.getUTCDate();
        }
        if (d.getUTCHours() < 10) {
            folder += "0" + d.getUTCHours();
        } else {
            folder += d.getUTCHours();
        }
        if (d.getUTCMinutes() < 10) {
            folder += "0" + d.getUTCMinutes();
        } else {
            folder += d.getUTCMinutes();
        }
        if (d.getUTCSeconds() < 10) {
            folder += "0" + d.getUTCSeconds();
        } else {
            folder += d.getUTCSeconds();
        }
        
        try {
            fs.mkdirSync(os.homedir() + "/" + folder, {recursive: true});
            r.response = folder;
        } catch (e) {
            r.status = 403;
        }
        break;
    case "scandir":
        try {
            d = fs.readdirSync(tgt, {withFileTypes: true});
        } catch(e) {
            r.status = 404;
            break;
        }
        let t = ""
        for (let i = 0; i < d.length; i++) {
            t += d[i].name;
            if (d[i].isDirectory()) {
                t += "/\n";
            } else {
                t += "\n";
            }
        }
        enc = new TextEncoder();
        r.response = enc.encode(t);
        break;
    case "filesize":
        try {
            let st = fs.statSync(tgt);
            r.response = st.size;
        } catch (e) {
            r.status = 404;
        }
        break;
    case "read":
        try {
            if (size < 1) {
                let st = fs.statSync(tgt);
                size = st.size;
            }
            if (seek < 0) {
                seek = 0;
            }
            if (size > 0) {
                d = new Uint8Array(size);
                fd = fs.openSync(tgt, "r");
                fs.readSync(fd, d, 0, size, seek);
                fs.closeSync(fd);
            } else {
                d = new ArrayBuffer();
            }
        } catch (e) {
            r.status = 404;
            d = null;
            break;
        }
        r.response = d;
        break;
    case "write":
        try {
            fs.mkdirSync(os.homedir() + "/" + folder, {recursive: true});
        } catch(e) {

        }
        try {
            try {
                fd = fs.openSync(tgt, "rs+");
            } catch(e) {
                fd = fs.openSync(tgt, "w");
            }
            if (size < 1) {
                size = data.size;
            }
            if (seek < 0) {
                seek = 0;
                fs.truncateSync(fd);
            } 
            fs.writeSync(fd, data, 0, size, seek);
            fs.closeSync(fd);
            r.response = folder + "/" + target;
        } catch (e) {
            r.status = 404;
            break;
        }
        break;
    case "unlink":
        try {
            fs.unlinkSync(tgt);
            r.response = folder + "/" + target;
        } catch (e) {
            r.status = 403;
        }
        break;
    case "mkdir":
        try {
            fs.mkdirSync(tgt, {recursive: true});
        } catch (e) {
            r.status = 403;
        }
        r.response = folder + "/" + target;
        break;
    case "rmdir":
        try {
            fs.rmdirSync(tgt);
        } catch (e) {
            r.status = 403;
        }
        r.response = folder + "/" + target;
        break;
    default:
        console.log(folder);
    }
    callback(r);
}
); // expose

