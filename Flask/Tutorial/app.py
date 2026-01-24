from flask import Flask
app = Flask(__name__)

@app.route('/')
def home():
    return "This is home page mm,hhhhhhhs"

@app.route('/about')
def about():
    return "This is about page "

app.add_url_rule('/home','home')

if __name__ == '__main__':
    app.run(debug=True)