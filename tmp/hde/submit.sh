#!/bin/sh

curl --header "Content-Type: application/json" \
  --user zaki.oussama@gmail.com:0042489593 \
  --request POST \
  --data '{"github_url": "https://gist.github.com/OussaZaki/7383a8bb5601ba1f1c512a91e5b4edac","contact_email": "zaki.oussama@gmail.com"}' \
  https://hdechallenge-solve.appspot.com/challenge/003/endpoint

