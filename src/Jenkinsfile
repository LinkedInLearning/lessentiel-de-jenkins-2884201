pipeline {
    agent{
        docker {
            image 'node:alpine'
            args '-e NPM_CONFIG_LOGLEVEL=info'
        }
    }
    stages{
        stage('build') {
            steps {
                sh 'sh ./scripts/build.sh'
            }
        }
        stage('test') {
            steps {
                sh 'sh ./scripts/test.sh'
            }
        }        
    }
}