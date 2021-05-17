#!/usr/bin/env sh

npm install --quiet http serve-static finalhandler

node scripts/validate.js http://localhost $1
