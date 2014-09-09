#coding:utf-8
from flask import Flask,render_template
import sys

app = Flask(__name__)
ip = sys.argv[1]

@app.route('/axis')
def index():
    return render_template('index.html', ip=ip)

if __name__ == '__main__':
    app.run(host=ip, port=5000, debug=True)
