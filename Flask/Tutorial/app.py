from flask import Flask,render_template
app = Flask(__name__)

@app.route('/<int:num>')
def home(num):
    return render_template('index.html',name = num  )

@app.route('/about')
def about():
    return "This is about page "

app.add_url_rule('/home','home') 

if __name__ == '__main__':
    app.run(debug=True)