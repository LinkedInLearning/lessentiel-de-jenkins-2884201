var finalhandler = require('finalhandler')
var serveStatic = require('serve-static') 
var http = require('http')
var serve = serveStatic('./out', { 'index': ['../scripts/validate.html'] })

var server = http.createServer(function onRequest (req, res) {
    let ok = req.url=='/ok'

    if(ok || req.url=='/ko') {
        if(ok) {
            console.log('Test ok')
            exitcode = 0
        } else {
            console.error('Test ko')
            exitcode = -1
        }
        res.end('Vous pouvez fermer cette page.')
        server.close(() => process.exit(exitcode))
    }
    serve(req, res, finalhandler(req, res))
})
let port = parseInt(process.argv[3])

server.listen(port)
console.log(`Validation: ${process.argv[2]}:${port}`)
