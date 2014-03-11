from flask import Flask,url_for,session,escape,request,redirect
from flask import render_template

app = Flask(__name__)

@app.route('/')
def hello_world():
	return 'Hello World!'

@app.route('/student/<username>/')
def student(username):
	return 'Hello %s' % username

@app.route('/student/<username>/<int:user_id>')
def student2(usename,user_id):
	return 'Hello %s , %d' % (username, user_id)

@app.route('/login', methods=['POST','GET'])
def login():
		if request.method == "POST":
			name = request.form['name']
			passwd = request.form['password']
			if name : session['username']=name
			return render_template('new.html',name = name)
		
		else :
			return render_template('login.html')

@app.route('/')
def index():
	if 'username' in session:
		return 'Logged in as %s <p> <a href="/logout"> logout</a>' % escape(session['username'])
	return 'You are not logged in <p> <a href="/login"> login gogo</a>'

@app.route('/logout')
def logout():
	session.pop('username', None)
	return redirect(url_for('index'))

if __name__ == '__main__':
	app.debug=True
	app.secret_key='\x9ci\x1c\x843\x15{7\xcf\x90\xb2\x85\r=.\x90?\xf9\x92\xbc\xe9\xac\xa3\x02'
	app.run()

	app.debug = True
	app.run()
